// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turret_control:action/RotateTurret.idl
// generated code does not contain a copyright notice

#ifndef TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__BUILDER_HPP_
#define TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turret_control/action/detail/rotate_turret__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turret_control
{

namespace action
{

namespace builder
{

class Init_RotateTurret_Goal_target_angle
{
public:
  Init_RotateTurret_Goal_target_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turret_control::action::RotateTurret_Goal target_angle(::turret_control::action::RotateTurret_Goal::_target_angle_type arg)
  {
    msg_.target_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turret_control::action::RotateTurret_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turret_control::action::RotateTurret_Goal>()
{
  return turret_control::action::builder::Init_RotateTurret_Goal_target_angle();
}

}  // namespace turret_control


namespace turret_control
{

namespace action
{

namespace builder
{

class Init_RotateTurret_Result_result_message
{
public:
  Init_RotateTurret_Result_result_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turret_control::action::RotateTurret_Result result_message(::turret_control::action::RotateTurret_Result::_result_message_type arg)
  {
    msg_.result_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turret_control::action::RotateTurret_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turret_control::action::RotateTurret_Result>()
{
  return turret_control::action::builder::Init_RotateTurret_Result_result_message();
}

}  // namespace turret_control


namespace turret_control
{

namespace action
{

namespace builder
{

class Init_RotateTurret_Feedback_current_angle
{
public:
  Init_RotateTurret_Feedback_current_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turret_control::action::RotateTurret_Feedback current_angle(::turret_control::action::RotateTurret_Feedback::_current_angle_type arg)
  {
    msg_.current_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turret_control::action::RotateTurret_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turret_control::action::RotateTurret_Feedback>()
{
  return turret_control::action::builder::Init_RotateTurret_Feedback_current_angle();
}

}  // namespace turret_control


namespace turret_control
{

namespace action
{

namespace builder
{

class Init_RotateTurret_SendGoal_Request_goal
{
public:
  explicit Init_RotateTurret_SendGoal_Request_goal(::turret_control::action::RotateTurret_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::turret_control::action::RotateTurret_SendGoal_Request goal(::turret_control::action::RotateTurret_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turret_control::action::RotateTurret_SendGoal_Request msg_;
};

class Init_RotateTurret_SendGoal_Request_goal_id
{
public:
  Init_RotateTurret_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateTurret_SendGoal_Request_goal goal_id(::turret_control::action::RotateTurret_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RotateTurret_SendGoal_Request_goal(msg_);
  }

private:
  ::turret_control::action::RotateTurret_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turret_control::action::RotateTurret_SendGoal_Request>()
{
  return turret_control::action::builder::Init_RotateTurret_SendGoal_Request_goal_id();
}

}  // namespace turret_control


namespace turret_control
{

namespace action
{

namespace builder
{

class Init_RotateTurret_SendGoal_Response_stamp
{
public:
  explicit Init_RotateTurret_SendGoal_Response_stamp(::turret_control::action::RotateTurret_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::turret_control::action::RotateTurret_SendGoal_Response stamp(::turret_control::action::RotateTurret_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turret_control::action::RotateTurret_SendGoal_Response msg_;
};

class Init_RotateTurret_SendGoal_Response_accepted
{
public:
  Init_RotateTurret_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateTurret_SendGoal_Response_stamp accepted(::turret_control::action::RotateTurret_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_RotateTurret_SendGoal_Response_stamp(msg_);
  }

private:
  ::turret_control::action::RotateTurret_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turret_control::action::RotateTurret_SendGoal_Response>()
{
  return turret_control::action::builder::Init_RotateTurret_SendGoal_Response_accepted();
}

}  // namespace turret_control


namespace turret_control
{

namespace action
{

namespace builder
{

class Init_RotateTurret_GetResult_Request_goal_id
{
public:
  Init_RotateTurret_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turret_control::action::RotateTurret_GetResult_Request goal_id(::turret_control::action::RotateTurret_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turret_control::action::RotateTurret_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turret_control::action::RotateTurret_GetResult_Request>()
{
  return turret_control::action::builder::Init_RotateTurret_GetResult_Request_goal_id();
}

}  // namespace turret_control


namespace turret_control
{

namespace action
{

namespace builder
{

class Init_RotateTurret_GetResult_Response_result
{
public:
  explicit Init_RotateTurret_GetResult_Response_result(::turret_control::action::RotateTurret_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::turret_control::action::RotateTurret_GetResult_Response result(::turret_control::action::RotateTurret_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turret_control::action::RotateTurret_GetResult_Response msg_;
};

class Init_RotateTurret_GetResult_Response_status
{
public:
  Init_RotateTurret_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateTurret_GetResult_Response_result status(::turret_control::action::RotateTurret_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RotateTurret_GetResult_Response_result(msg_);
  }

private:
  ::turret_control::action::RotateTurret_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turret_control::action::RotateTurret_GetResult_Response>()
{
  return turret_control::action::builder::Init_RotateTurret_GetResult_Response_status();
}

}  // namespace turret_control


namespace turret_control
{

namespace action
{

namespace builder
{

class Init_RotateTurret_FeedbackMessage_feedback
{
public:
  explicit Init_RotateTurret_FeedbackMessage_feedback(::turret_control::action::RotateTurret_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::turret_control::action::RotateTurret_FeedbackMessage feedback(::turret_control::action::RotateTurret_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turret_control::action::RotateTurret_FeedbackMessage msg_;
};

class Init_RotateTurret_FeedbackMessage_goal_id
{
public:
  Init_RotateTurret_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateTurret_FeedbackMessage_feedback goal_id(::turret_control::action::RotateTurret_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RotateTurret_FeedbackMessage_feedback(msg_);
  }

private:
  ::turret_control::action::RotateTurret_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::turret_control::action::RotateTurret_FeedbackMessage>()
{
  return turret_control::action::builder::Init_RotateTurret_FeedbackMessage_goal_id();
}

}  // namespace turret_control

#endif  // TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__BUILDER_HPP_
