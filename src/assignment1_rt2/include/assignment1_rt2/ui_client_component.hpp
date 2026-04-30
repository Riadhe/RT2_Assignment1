#ifndef ASSIGNMENT1_RT2_UI_CLIENT_COMPONENT_HPP
#define ASSIGNMENT1_RT2_UI_CLIENT_COMPONENT_HPP

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "assignment1_interfaces/action/navigate.hpp"
#include <thread>

namespace assignment1_rt2
{

class UiClientComponent : public rclcpp::Node
{
public:
  using Navigate = assignment1_interfaces::action::Navigate;
  using GoalHandleNavigate = rclcpp_action::ClientGoalHandle<Navigate>;

  explicit UiClientComponent(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
  rclcpp_action::Client<Navigate>::SharedPtr client_ptr_;
  
  // Thread to wait for user input from the terminal without blocking the ROS 2 node
  std::thread user_input_thread_;
  
  // Store the active Goal Handle to allow cancellation of the current goal
  GoalHandleNavigate::SharedPtr current_goal_handle_;

  // Function containing the logic to be executed in the separate thread
  void user_input_loop();

  // Action Client callback functions
  void goal_response_callback(const GoalHandleNavigate::SharedPtr & goal_handle);
  void feedback_callback(GoalHandleNavigate::SharedPtr, const std::shared_ptr<const Navigate::Feedback> feedback);
  void result_callback(const GoalHandleNavigate::WrappedResult & result);
};

}  // namespace assignment1_rt2

#endif  // ASSIGNMENT1_RT2_UI_CLIENT_COMPONENT_HPP