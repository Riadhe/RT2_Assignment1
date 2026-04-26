// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from assignment1_interfaces:action/Navigate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "assignment1_interfaces/action/navigate.hpp"


#ifndef ASSIGNMENT1_INTERFACES__ACTION__DETAIL__NAVIGATE__BUILDER_HPP_
#define ASSIGNMENT1_INTERFACES__ACTION__DETAIL__NAVIGATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "assignment1_interfaces/action/detail/navigate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_Goal_theta
{
public:
  explicit Init_Navigate_Goal_theta(::assignment1_interfaces::action::Navigate_Goal & msg)
  : msg_(msg)
  {}
  ::assignment1_interfaces::action::Navigate_Goal theta(::assignment1_interfaces::action::Navigate_Goal::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_Goal msg_;
};

class Init_Navigate_Goal_y
{
public:
  explicit Init_Navigate_Goal_y(::assignment1_interfaces::action::Navigate_Goal & msg)
  : msg_(msg)
  {}
  Init_Navigate_Goal_theta y(::assignment1_interfaces::action::Navigate_Goal::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Navigate_Goal_theta(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_Goal msg_;
};

class Init_Navigate_Goal_x
{
public:
  Init_Navigate_Goal_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_Goal_y x(::assignment1_interfaces::action::Navigate_Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Navigate_Goal_y(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_Goal>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_Goal_x();
}

}  // namespace assignment1_interfaces


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_Result_success
{
public:
  Init_Navigate_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::assignment1_interfaces::action::Navigate_Result success(::assignment1_interfaces::action::Navigate_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_Result>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_Result_success();
}

}  // namespace assignment1_interfaces


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_Feedback_distance_to_goal
{
public:
  explicit Init_Navigate_Feedback_distance_to_goal(::assignment1_interfaces::action::Navigate_Feedback & msg)
  : msg_(msg)
  {}
  ::assignment1_interfaces::action::Navigate_Feedback distance_to_goal(::assignment1_interfaces::action::Navigate_Feedback::_distance_to_goal_type arg)
  {
    msg_.distance_to_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_Feedback msg_;
};

class Init_Navigate_Feedback_current_theta
{
public:
  explicit Init_Navigate_Feedback_current_theta(::assignment1_interfaces::action::Navigate_Feedback & msg)
  : msg_(msg)
  {}
  Init_Navigate_Feedback_distance_to_goal current_theta(::assignment1_interfaces::action::Navigate_Feedback::_current_theta_type arg)
  {
    msg_.current_theta = std::move(arg);
    return Init_Navigate_Feedback_distance_to_goal(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_Feedback msg_;
};

class Init_Navigate_Feedback_current_y
{
public:
  explicit Init_Navigate_Feedback_current_y(::assignment1_interfaces::action::Navigate_Feedback & msg)
  : msg_(msg)
  {}
  Init_Navigate_Feedback_current_theta current_y(::assignment1_interfaces::action::Navigate_Feedback::_current_y_type arg)
  {
    msg_.current_y = std::move(arg);
    return Init_Navigate_Feedback_current_theta(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_Feedback msg_;
};

class Init_Navigate_Feedback_current_x
{
public:
  Init_Navigate_Feedback_current_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_Feedback_current_y current_x(::assignment1_interfaces::action::Navigate_Feedback::_current_x_type arg)
  {
    msg_.current_x = std::move(arg);
    return Init_Navigate_Feedback_current_y(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_Feedback>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_Feedback_current_x();
}

}  // namespace assignment1_interfaces


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_SendGoal_Request_goal
{
public:
  explicit Init_Navigate_SendGoal_Request_goal(::assignment1_interfaces::action::Navigate_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::assignment1_interfaces::action::Navigate_SendGoal_Request goal(::assignment1_interfaces::action::Navigate_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_SendGoal_Request msg_;
};

class Init_Navigate_SendGoal_Request_goal_id
{
public:
  Init_Navigate_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_SendGoal_Request_goal goal_id(::assignment1_interfaces::action::Navigate_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Navigate_SendGoal_Request_goal(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_SendGoal_Request>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_SendGoal_Request_goal_id();
}

}  // namespace assignment1_interfaces


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_SendGoal_Response_stamp
{
public:
  explicit Init_Navigate_SendGoal_Response_stamp(::assignment1_interfaces::action::Navigate_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::assignment1_interfaces::action::Navigate_SendGoal_Response stamp(::assignment1_interfaces::action::Navigate_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_SendGoal_Response msg_;
};

class Init_Navigate_SendGoal_Response_accepted
{
public:
  Init_Navigate_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_SendGoal_Response_stamp accepted(::assignment1_interfaces::action::Navigate_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Navigate_SendGoal_Response_stamp(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_SendGoal_Response>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_SendGoal_Response_accepted();
}

}  // namespace assignment1_interfaces


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_SendGoal_Event_response
{
public:
  explicit Init_Navigate_SendGoal_Event_response(::assignment1_interfaces::action::Navigate_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::assignment1_interfaces::action::Navigate_SendGoal_Event response(::assignment1_interfaces::action::Navigate_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_SendGoal_Event msg_;
};

class Init_Navigate_SendGoal_Event_request
{
public:
  explicit Init_Navigate_SendGoal_Event_request(::assignment1_interfaces::action::Navigate_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Navigate_SendGoal_Event_response request(::assignment1_interfaces::action::Navigate_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Navigate_SendGoal_Event_response(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_SendGoal_Event msg_;
};

class Init_Navigate_SendGoal_Event_info
{
public:
  Init_Navigate_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_SendGoal_Event_request info(::assignment1_interfaces::action::Navigate_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Navigate_SendGoal_Event_request(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_SendGoal_Event>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_SendGoal_Event_info();
}

}  // namespace assignment1_interfaces


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_GetResult_Request_goal_id
{
public:
  Init_Navigate_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::assignment1_interfaces::action::Navigate_GetResult_Request goal_id(::assignment1_interfaces::action::Navigate_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_GetResult_Request>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_GetResult_Request_goal_id();
}

}  // namespace assignment1_interfaces


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_GetResult_Response_result
{
public:
  explicit Init_Navigate_GetResult_Response_result(::assignment1_interfaces::action::Navigate_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::assignment1_interfaces::action::Navigate_GetResult_Response result(::assignment1_interfaces::action::Navigate_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_GetResult_Response msg_;
};

class Init_Navigate_GetResult_Response_status
{
public:
  Init_Navigate_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_GetResult_Response_result status(::assignment1_interfaces::action::Navigate_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Navigate_GetResult_Response_result(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_GetResult_Response>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_GetResult_Response_status();
}

}  // namespace assignment1_interfaces


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_GetResult_Event_response
{
public:
  explicit Init_Navigate_GetResult_Event_response(::assignment1_interfaces::action::Navigate_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::assignment1_interfaces::action::Navigate_GetResult_Event response(::assignment1_interfaces::action::Navigate_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_GetResult_Event msg_;
};

class Init_Navigate_GetResult_Event_request
{
public:
  explicit Init_Navigate_GetResult_Event_request(::assignment1_interfaces::action::Navigate_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Navigate_GetResult_Event_response request(::assignment1_interfaces::action::Navigate_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Navigate_GetResult_Event_response(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_GetResult_Event msg_;
};

class Init_Navigate_GetResult_Event_info
{
public:
  Init_Navigate_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_GetResult_Event_request info(::assignment1_interfaces::action::Navigate_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Navigate_GetResult_Event_request(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_GetResult_Event>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_GetResult_Event_info();
}

}  // namespace assignment1_interfaces


namespace assignment1_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_FeedbackMessage_feedback
{
public:
  explicit Init_Navigate_FeedbackMessage_feedback(::assignment1_interfaces::action::Navigate_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::assignment1_interfaces::action::Navigate_FeedbackMessage feedback(::assignment1_interfaces::action::Navigate_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_FeedbackMessage msg_;
};

class Init_Navigate_FeedbackMessage_goal_id
{
public:
  Init_Navigate_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_FeedbackMessage_feedback goal_id(::assignment1_interfaces::action::Navigate_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Navigate_FeedbackMessage_feedback(msg_);
  }

private:
  ::assignment1_interfaces::action::Navigate_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::assignment1_interfaces::action::Navigate_FeedbackMessage>()
{
  return assignment1_interfaces::action::builder::Init_Navigate_FeedbackMessage_goal_id();
}

}  // namespace assignment1_interfaces

#endif  // ASSIGNMENT1_INTERFACES__ACTION__DETAIL__NAVIGATE__BUILDER_HPP_
