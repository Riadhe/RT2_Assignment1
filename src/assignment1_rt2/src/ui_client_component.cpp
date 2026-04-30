#include "assignment1_rt2/ui_client_component.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include <iostream>

namespace assignment1_rt2
{

UiClientComponent::UiClientComponent(const rclcpp::NodeOptions & options)
: Node("ui_client", options)
{
  client_ptr_ = rclcpp_action::create_client<Navigate>(this, "navigate");

  // Run the UI in a separate thread so the ROS 2 node is not blocked in the background
  user_input_thread_ = std::thread(&UiClientComponent::user_input_loop, this);
  user_input_thread_.detach();
}

void UiClientComponent::user_input_loop()
{
  while (rclcpp::ok()) {
    std::cout << "\n------------------------ Robot Navigation UI ------------------------\n";
    std::cout << "Enter target (x y theta) parameters, or type 'c + enter' to cancel current goal: " << std::flush;    
    std::string input;
    std::cin >> input;

    if (input == "c" || input == "C") {
      if (current_goal_handle_) {
        RCLCPP_INFO(this->get_logger(), "Sending cancel request...");
        client_ptr_->async_cancel_goal(current_goal_handle_);
        current_goal_handle_.reset(); // Reset the active goal handle after canceling
      } else {
        std::cout << "No active goal to cancel!\n";
      }
      continue;
    }

    // If the input is not 'c', parse the x, y, theta coordinates
    try {
      double x = std::stod(input);
      double y, theta;
      std::cin >> y >> theta;

      if (!client_ptr_->wait_for_action_server(std::chrono::seconds(5))) {
        RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
        continue;
      }

      auto goal_msg = Navigate::Goal();
      goal_msg.x = x;
      goal_msg.y = y;
      goal_msg.theta = theta;

      RCLCPP_INFO(this->get_logger(), "Sending goal: x=%.2f, y=%.2f, theta=%.2f", x, y, theta);

      auto send_goal_options = rclcpp_action::Client<Navigate>::SendGoalOptions();
      send_goal_options.goal_response_callback = std::bind(&UiClientComponent::goal_response_callback, this, std::placeholders::_1);
      send_goal_options.feedback_callback = std::bind(&UiClientComponent::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);
      send_goal_options.result_callback = std::bind(&UiClientComponent::result_callback, this, std::placeholders::_1);

      client_ptr_->async_send_goal(goal_msg, send_goal_options);

    } catch (const std::invalid_argument& e) {
      std::cout << "Invalid input! Please enter numbers for x, y, theta.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

void UiClientComponent::goal_response_callback(const GoalHandleNavigate::SharedPtr & goal_handle)
{
  if (!goal_handle) {
    RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
  } else {
    RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
    current_goal_handle_ = goal_handle; // Store the goal handle so we can cancel it later if needed
  }
}

void UiClientComponent::feedback_callback(
  GoalHandleNavigate::SharedPtr,
  const std::shared_ptr<const Navigate::Feedback> feedback)
{
  // Print the continuous feedback (distance to goal) received from the server
  RCLCPP_INFO(this->get_logger(), "Distance to goal: %.2f", feedback->distance_to_goal);
}

void UiClientComponent::result_callback(const GoalHandleNavigate::WrappedResult & result)
{
  current_goal_handle_.reset(); // The task is complete, reset the active goal handle

  switch (result.code) {
    case rclcpp_action::ResultCode::SUCCEEDED:
      RCLCPP_INFO(this->get_logger(), "Goal succeeded! Robot reached the target.");
      break;
    case rclcpp_action::ResultCode::ABORTED:
      RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
      break;
    case rclcpp_action::ResultCode::CANCELED:
      RCLCPP_INFO(this->get_logger(), "Goal was canceled");
      break;
    default:
      RCLCPP_ERROR(this->get_logger(), "Unknown result code");
      break;
  }
}

}  // namespace assignment1_rt2

// Macro that registers the Component (plugin) to be loaded by the Container
RCLCPP_COMPONENTS_REGISTER_NODE(assignment1_rt2::UiClientComponent)