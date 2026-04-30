#include "assignment1_rt2/nav_server_component.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <cmath>
#include "rclcpp_components/register_node_macro.hpp"

namespace assignment1_rt2
{

NavServerComponent::NavServerComponent(const rclcpp::NodeOptions & options)
: Node("nav_server", options), current_x_(0.0), current_y_(0.0), current_theta_(0.0)
{
  using namespace std::placeholders;

  // 1. Create a Publisher for velocity commands
  cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

  // 2. Create a Subscriber for Odometry to track the robot's pose
  odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
    "odom", 10, std::bind(&NavServerComponent::odom_callback, this, _1));

  // 3. Create the Action Server
  action_server_ = rclcpp_action::create_server<Navigate>(
    this,
    "navigate",
    std::bind(&NavServerComponent::handle_goal, this, _1, _2),
    std::bind(&NavServerComponent::handle_cancel, this, _1),
    std::bind(&NavServerComponent::handle_accepted, this, _1));
    
  RCLCPP_INFO(this->get_logger(), "Navigation Server Component Started.");
}

// ---------------------------------------------------------
// Action Server Callbacks
// ---------------------------------------------------------
rclcpp_action::GoalResponse NavServerComponent::handle_goal(
  const rclcpp_action::GoalUUID & uuid,
  std::shared_ptr<const Navigate::Goal> goal)
{
  (void)uuid;
  RCLCPP_INFO(this->get_logger(), "Received goal request: x=%.2f, y=%.2f, theta=%.2f", goal->x, goal->y, goal->theta);
  return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse NavServerComponent::handle_cancel(
  const std::shared_ptr<GoalHandleNavigate> goal_handle)
{
  RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
  (void)goal_handle;
  return rclcpp_action::CancelResponse::ACCEPT;
}

void NavServerComponent::handle_accepted(const std::shared_ptr<GoalHandleNavigate> goal_handle)
{
  // Run the execute function in a separate thread to avoid blocking the Node
  std::thread(&NavServerComponent::execute, this, goal_handle).detach();
}

// ---------------------------------------------------------
// Odometry Callback (Where is the robot currently?)
// ---------------------------------------------------------
void NavServerComponent::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
  current_x_ = msg->pose.pose.position.x;
  current_y_ = msg->pose.pose.position.y;

  // Convert Quaternion to Yaw angle (Theta)
  tf2::Quaternion q(
    msg->pose.pose.orientation.x,
    msg->pose.pose.orientation.y,
    msg->pose.pose.orientation.z,
    msg->pose.pose.orientation.w);
  tf2::Matrix3x3 m(q);
  double roll, pitch, yaw;
  m.getRPY(roll, pitch, yaw);
  current_theta_ = yaw;
}

// ---------------------------------------------------------
// Main Execution Logic
// ---------------------------------------------------------
void NavServerComponent::execute(const std::shared_ptr<GoalHandleNavigate> goal_handle)
{
  RCLCPP_INFO(this->get_logger(), "Executing goal...");
  rclcpp::Rate loop_rate(10); // 10 Hz
  
  const auto goal = goal_handle->get_goal();
  auto feedback = std::make_shared<Navigate::Feedback>();
  auto result = std::make_shared<Navigate::Result>();
  auto twist_msg = geometry_msgs::msg::Twist();

  double distance_tolerance = 0.1;
  
  while (rclcpp::ok()) {
    // 1. Check if the user requested a cancellation
    if (goal_handle->is_canceling()) {
      twist_msg.linear.x = 0.0;
      twist_msg.angular.z = 0.0;
      cmd_vel_pub_->publish(twist_msg); // Stop the robot
      result->success = false;
      goal_handle->canceled(result);
      RCLCPP_INFO(this->get_logger(), "Goal canceled.");
      return;
    }

    // 2. Calculate the errors (distance and angle to the goal)
    double dx = goal->x - current_x_;
    double dy = goal->y - current_y_;
    double distance = std::sqrt(dx*dx + dy*dy);
    double target_angle = std::atan2(dy, dx);
    double angle_error = target_angle - current_theta_;

    // Normalize the angle to be between -pi and pi
    while (angle_error > M_PI) angle_error -= 2.0 * M_PI;
    while (angle_error < -M_PI) angle_error += 2.0 * M_PI;

    // 3. Movement logic (Simple Proportional Controller)
    if (distance > distance_tolerance) {
      twist_msg.linear.x = 0.5 * distance; // Linear speed (forward)
      twist_msg.angular.z = 1.0 * angle_error; // Angular speed (rotation)
      
      // Cap the maximum linear speed
      if (twist_msg.linear.x > 0.5) twist_msg.linear.x = 0.5;
    } else {
      // Reached x, y .. now rotate to the desired theta
      double final_angle_error = goal->theta - current_theta_;
      while (final_angle_error > M_PI) final_angle_error -= 2.0 * M_PI;
      while (final_angle_error < -M_PI) final_angle_error += 2.0 * M_PI;
      
      if (std::abs(final_angle_error) > 0.1) {
        twist_msg.linear.x = 0.0;
        twist_msg.angular.z = 1.0 * final_angle_error;
      } else {
        // Target reached successfully
        twist_msg.linear.x = 0.0;
        twist_msg.angular.z = 0.0;
        cmd_vel_pub_->publish(twist_msg);
        break; 
      }
    }

    // 4. Publish velocity and feedback
    cmd_vel_pub_->publish(twist_msg);
    feedback->current_x = current_x_;
    feedback->current_y = current_y_;
    feedback->current_theta = current_theta_;
    feedback->distance_to_goal = distance;
    goal_handle->publish_feedback(feedback);

    loop_rate.sleep();
  }

  // 5. Confirm success
  if (rclcpp::ok()) {
    result->success = true;
    goal_handle->succeed(result);
    RCLCPP_INFO(this->get_logger(), "Goal succeeded!");
  }
}

}  // namespace assignment1_rt2

// The macro that registers the Component (plugin) to run in a Container
RCLCPP_COMPONENTS_REGISTER_NODE(assignment1_rt2::NavServerComponent)