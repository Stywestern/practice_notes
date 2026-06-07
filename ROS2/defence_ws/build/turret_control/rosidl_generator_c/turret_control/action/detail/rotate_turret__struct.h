// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turret_control:action/RotateTurret.idl
// generated code does not contain a copyright notice

#ifndef TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__STRUCT_H_
#define TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/RotateTurret in the package turret_control.
typedef struct turret_control__action__RotateTurret_Goal
{
  double target_angle;
} turret_control__action__RotateTurret_Goal;

// Struct for a sequence of turret_control__action__RotateTurret_Goal.
typedef struct turret_control__action__RotateTurret_Goal__Sequence
{
  turret_control__action__RotateTurret_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turret_control__action__RotateTurret_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/RotateTurret in the package turret_control.
typedef struct turret_control__action__RotateTurret_Result
{
  rosidl_runtime_c__String result_message;
} turret_control__action__RotateTurret_Result;

// Struct for a sequence of turret_control__action__RotateTurret_Result.
typedef struct turret_control__action__RotateTurret_Result__Sequence
{
  turret_control__action__RotateTurret_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turret_control__action__RotateTurret_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/RotateTurret in the package turret_control.
typedef struct turret_control__action__RotateTurret_Feedback
{
  double current_angle;
} turret_control__action__RotateTurret_Feedback;

// Struct for a sequence of turret_control__action__RotateTurret_Feedback.
typedef struct turret_control__action__RotateTurret_Feedback__Sequence
{
  turret_control__action__RotateTurret_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turret_control__action__RotateTurret_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "turret_control/action/detail/rotate_turret__struct.h"

/// Struct defined in action/RotateTurret in the package turret_control.
typedef struct turret_control__action__RotateTurret_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  turret_control__action__RotateTurret_Goal goal;
} turret_control__action__RotateTurret_SendGoal_Request;

// Struct for a sequence of turret_control__action__RotateTurret_SendGoal_Request.
typedef struct turret_control__action__RotateTurret_SendGoal_Request__Sequence
{
  turret_control__action__RotateTurret_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turret_control__action__RotateTurret_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/RotateTurret in the package turret_control.
typedef struct turret_control__action__RotateTurret_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} turret_control__action__RotateTurret_SendGoal_Response;

// Struct for a sequence of turret_control__action__RotateTurret_SendGoal_Response.
typedef struct turret_control__action__RotateTurret_SendGoal_Response__Sequence
{
  turret_control__action__RotateTurret_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turret_control__action__RotateTurret_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/RotateTurret in the package turret_control.
typedef struct turret_control__action__RotateTurret_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} turret_control__action__RotateTurret_GetResult_Request;

// Struct for a sequence of turret_control__action__RotateTurret_GetResult_Request.
typedef struct turret_control__action__RotateTurret_GetResult_Request__Sequence
{
  turret_control__action__RotateTurret_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turret_control__action__RotateTurret_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "turret_control/action/detail/rotate_turret__struct.h"

/// Struct defined in action/RotateTurret in the package turret_control.
typedef struct turret_control__action__RotateTurret_GetResult_Response
{
  int8_t status;
  turret_control__action__RotateTurret_Result result;
} turret_control__action__RotateTurret_GetResult_Response;

// Struct for a sequence of turret_control__action__RotateTurret_GetResult_Response.
typedef struct turret_control__action__RotateTurret_GetResult_Response__Sequence
{
  turret_control__action__RotateTurret_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turret_control__action__RotateTurret_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "turret_control/action/detail/rotate_turret__struct.h"

/// Struct defined in action/RotateTurret in the package turret_control.
typedef struct turret_control__action__RotateTurret_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  turret_control__action__RotateTurret_Feedback feedback;
} turret_control__action__RotateTurret_FeedbackMessage;

// Struct for a sequence of turret_control__action__RotateTurret_FeedbackMessage.
typedef struct turret_control__action__RotateTurret_FeedbackMessage__Sequence
{
  turret_control__action__RotateTurret_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turret_control__action__RotateTurret_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__STRUCT_H_
