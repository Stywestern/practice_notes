// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turret_control:action/RotateTurret.idl
// generated code does not contain a copyright notice

#ifndef TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__TRAITS_HPP_
#define TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turret_control/action/detail/rotate_turret__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turret_control
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateTurret_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_angle
  {
    out << "target_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.target_angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateTurret_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.target_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateTurret_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace turret_control

namespace rosidl_generator_traits
{

[[deprecated("use turret_control::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turret_control::action::RotateTurret_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  turret_control::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turret_control::action::to_yaml() instead")]]
inline std::string to_yaml(const turret_control::action::RotateTurret_Goal & msg)
{
  return turret_control::action::to_yaml(msg);
}

template<>
inline const char * data_type<turret_control::action::RotateTurret_Goal>()
{
  return "turret_control::action::RotateTurret_Goal";
}

template<>
inline const char * name<turret_control::action::RotateTurret_Goal>()
{
  return "turret_control/action/RotateTurret_Goal";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turret_control::action::RotateTurret_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace turret_control
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateTurret_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: result_message
  {
    out << "result_message: ";
    rosidl_generator_traits::value_to_yaml(msg.result_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateTurret_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result_message: ";
    rosidl_generator_traits::value_to_yaml(msg.result_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateTurret_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace turret_control

namespace rosidl_generator_traits
{

[[deprecated("use turret_control::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turret_control::action::RotateTurret_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  turret_control::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turret_control::action::to_yaml() instead")]]
inline std::string to_yaml(const turret_control::action::RotateTurret_Result & msg)
{
  return turret_control::action::to_yaml(msg);
}

template<>
inline const char * data_type<turret_control::action::RotateTurret_Result>()
{
  return "turret_control::action::RotateTurret_Result";
}

template<>
inline const char * name<turret_control::action::RotateTurret_Result>()
{
  return "turret_control/action/RotateTurret_Result";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<turret_control::action::RotateTurret_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace turret_control
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateTurret_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_angle
  {
    out << "current_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.current_angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateTurret_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.current_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateTurret_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace turret_control

namespace rosidl_generator_traits
{

[[deprecated("use turret_control::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turret_control::action::RotateTurret_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  turret_control::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turret_control::action::to_yaml() instead")]]
inline std::string to_yaml(const turret_control::action::RotateTurret_Feedback & msg)
{
  return turret_control::action::to_yaml(msg);
}

template<>
inline const char * data_type<turret_control::action::RotateTurret_Feedback>()
{
  return "turret_control::action::RotateTurret_Feedback";
}

template<>
inline const char * name<turret_control::action::RotateTurret_Feedback>()
{
  return "turret_control/action/RotateTurret_Feedback";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turret_control::action::RotateTurret_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "turret_control/action/detail/rotate_turret__traits.hpp"

namespace turret_control
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateTurret_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateTurret_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateTurret_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace turret_control

namespace rosidl_generator_traits
{

[[deprecated("use turret_control::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turret_control::action::RotateTurret_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  turret_control::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turret_control::action::to_yaml() instead")]]
inline std::string to_yaml(const turret_control::action::RotateTurret_SendGoal_Request & msg)
{
  return turret_control::action::to_yaml(msg);
}

template<>
inline const char * data_type<turret_control::action::RotateTurret_SendGoal_Request>()
{
  return "turret_control::action::RotateTurret_SendGoal_Request";
}

template<>
inline const char * name<turret_control::action::RotateTurret_SendGoal_Request>()
{
  return "turret_control/action/RotateTurret_SendGoal_Request";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<turret_control::action::RotateTurret_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<turret_control::action::RotateTurret_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<turret_control::action::RotateTurret_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace turret_control
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateTurret_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateTurret_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateTurret_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace turret_control

namespace rosidl_generator_traits
{

[[deprecated("use turret_control::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turret_control::action::RotateTurret_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  turret_control::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turret_control::action::to_yaml() instead")]]
inline std::string to_yaml(const turret_control::action::RotateTurret_SendGoal_Response & msg)
{
  return turret_control::action::to_yaml(msg);
}

template<>
inline const char * data_type<turret_control::action::RotateTurret_SendGoal_Response>()
{
  return "turret_control::action::RotateTurret_SendGoal_Response";
}

template<>
inline const char * name<turret_control::action::RotateTurret_SendGoal_Response>()
{
  return "turret_control/action/RotateTurret_SendGoal_Response";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<turret_control::action::RotateTurret_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turret_control::action::RotateTurret_SendGoal>()
{
  return "turret_control::action::RotateTurret_SendGoal";
}

template<>
inline const char * name<turret_control::action::RotateTurret_SendGoal>()
{
  return "turret_control/action/RotateTurret_SendGoal";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<turret_control::action::RotateTurret_SendGoal_Request>::value &&
    has_fixed_size<turret_control::action::RotateTurret_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<turret_control::action::RotateTurret_SendGoal_Request>::value &&
    has_bounded_size<turret_control::action::RotateTurret_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<turret_control::action::RotateTurret_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<turret_control::action::RotateTurret_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turret_control::action::RotateTurret_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace turret_control
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateTurret_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateTurret_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateTurret_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace turret_control

namespace rosidl_generator_traits
{

[[deprecated("use turret_control::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turret_control::action::RotateTurret_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  turret_control::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turret_control::action::to_yaml() instead")]]
inline std::string to_yaml(const turret_control::action::RotateTurret_GetResult_Request & msg)
{
  return turret_control::action::to_yaml(msg);
}

template<>
inline const char * data_type<turret_control::action::RotateTurret_GetResult_Request>()
{
  return "turret_control::action::RotateTurret_GetResult_Request";
}

template<>
inline const char * name<turret_control::action::RotateTurret_GetResult_Request>()
{
  return "turret_control/action/RotateTurret_GetResult_Request";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<turret_control::action::RotateTurret_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "turret_control/action/detail/rotate_turret__traits.hpp"

namespace turret_control
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateTurret_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateTurret_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateTurret_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace turret_control

namespace rosidl_generator_traits
{

[[deprecated("use turret_control::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turret_control::action::RotateTurret_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  turret_control::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turret_control::action::to_yaml() instead")]]
inline std::string to_yaml(const turret_control::action::RotateTurret_GetResult_Response & msg)
{
  return turret_control::action::to_yaml(msg);
}

template<>
inline const char * data_type<turret_control::action::RotateTurret_GetResult_Response>()
{
  return "turret_control::action::RotateTurret_GetResult_Response";
}

template<>
inline const char * name<turret_control::action::RotateTurret_GetResult_Response>()
{
  return "turret_control/action/RotateTurret_GetResult_Response";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<turret_control::action::RotateTurret_Result>::value> {};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<turret_control::action::RotateTurret_Result>::value> {};

template<>
struct is_message<turret_control::action::RotateTurret_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turret_control::action::RotateTurret_GetResult>()
{
  return "turret_control::action::RotateTurret_GetResult";
}

template<>
inline const char * name<turret_control::action::RotateTurret_GetResult>()
{
  return "turret_control/action/RotateTurret_GetResult";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<turret_control::action::RotateTurret_GetResult_Request>::value &&
    has_fixed_size<turret_control::action::RotateTurret_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<turret_control::action::RotateTurret_GetResult_Request>::value &&
    has_bounded_size<turret_control::action::RotateTurret_GetResult_Response>::value
  >
{
};

template<>
struct is_service<turret_control::action::RotateTurret_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<turret_control::action::RotateTurret_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turret_control::action::RotateTurret_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "turret_control/action/detail/rotate_turret__traits.hpp"

namespace turret_control
{

namespace action
{

inline void to_flow_style_yaml(
  const RotateTurret_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateTurret_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateTurret_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace turret_control

namespace rosidl_generator_traits
{

[[deprecated("use turret_control::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turret_control::action::RotateTurret_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  turret_control::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turret_control::action::to_yaml() instead")]]
inline std::string to_yaml(const turret_control::action::RotateTurret_FeedbackMessage & msg)
{
  return turret_control::action::to_yaml(msg);
}

template<>
inline const char * data_type<turret_control::action::RotateTurret_FeedbackMessage>()
{
  return "turret_control::action::RotateTurret_FeedbackMessage";
}

template<>
inline const char * name<turret_control::action::RotateTurret_FeedbackMessage>()
{
  return "turret_control/action/RotateTurret_FeedbackMessage";
}

template<>
struct has_fixed_size<turret_control::action::RotateTurret_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<turret_control::action::RotateTurret_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<turret_control::action::RotateTurret_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<turret_control::action::RotateTurret_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<turret_control::action::RotateTurret_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<turret_control::action::RotateTurret>
  : std::true_type
{
};

template<>
struct is_action_goal<turret_control::action::RotateTurret_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<turret_control::action::RotateTurret_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<turret_control::action::RotateTurret_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__TRAITS_HPP_
