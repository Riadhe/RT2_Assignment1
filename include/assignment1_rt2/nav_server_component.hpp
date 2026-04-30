#ifndef ASSIGNMENT1_RT2_NAV_SERVER_COMPONENT_HPP
#define ASSIGNMENT1_RT2_NAV_SERVER_COMPONENT_HPP

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "assignment1_interfaces/action/navigate.hpp"

namespace assignment1_rt2
{

class NavServerComponent : public rclcpp::Node
{
public:
  using Navigate = assignment1_interfaces::action::Navigate;
  using GoalHandleNavigate = rclcpp_action::ServerGoalHandle<Navigate>;

  // Constructor accepting NodeOptions (required for ROS 2 Components)
  explicit NavServerComponent(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
  // Action Server callback functions
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const Navigate::Goal> goal);

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleNavigate> goal_handle);

  void handle_accepted(const std::shared_ptr<GoalHandleNavigate> goal_handle);

  void execute(const std::shared_ptr<GoalHandleNavigate> goal_handle);

  // Odometry callback to continuously track the robot's pose
  void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);

  // ROS 2 Action Server, Publisher, and Subscriber declarations
  rclcpp_action::Server<Navigate>::SharedPtr action_server_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;

  // Variables to store the robot's current position and orientation
  double current_x_;
  double current_y_;
  double current_theta_;
};

}  // namespace assignment1_rt2

#endif  // ASSIGNMENT1_RT2_NAV_SERVER_COMPONENT_HPP