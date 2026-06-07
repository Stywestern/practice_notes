// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from turret_control:action/RotateTurret.idl
// generated code does not contain a copyright notice

#ifndef TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__FUNCTIONS_H_
#define TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "turret_control/msg/rosidl_generator_c__visibility_control.h"

#include "turret_control/action/detail/rotate_turret__struct.h"

/// Initialize action/RotateTurret message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turret_control__action__RotateTurret_Goal
 * )) before or use
 * turret_control__action__RotateTurret_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Goal__init(turret_control__action__RotateTurret_Goal * msg);

/// Finalize action/RotateTurret message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Goal__fini(turret_control__action__RotateTurret_Goal * msg);

/// Create action/RotateTurret message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turret_control__action__RotateTurret_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_Goal *
turret_control__action__RotateTurret_Goal__create();

/// Destroy action/RotateTurret message.
/**
 * It calls
 * turret_control__action__RotateTurret_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Goal__destroy(turret_control__action__RotateTurret_Goal * msg);

/// Check for action/RotateTurret message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Goal__are_equal(const turret_control__action__RotateTurret_Goal * lhs, const turret_control__action__RotateTurret_Goal * rhs);

/// Copy a action/RotateTurret message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Goal__copy(
  const turret_control__action__RotateTurret_Goal * input,
  turret_control__action__RotateTurret_Goal * output);

/// Initialize array of action/RotateTurret messages.
/**
 * It allocates the memory for the number of elements and calls
 * turret_control__action__RotateTurret_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Goal__Sequence__init(turret_control__action__RotateTurret_Goal__Sequence * array, size_t size);

/// Finalize array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Goal__Sequence__fini(turret_control__action__RotateTurret_Goal__Sequence * array);

/// Create array of action/RotateTurret messages.
/**
 * It allocates the memory for the array and calls
 * turret_control__action__RotateTurret_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_Goal__Sequence *
turret_control__action__RotateTurret_Goal__Sequence__create(size_t size);

/// Destroy array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Goal__Sequence__destroy(turret_control__action__RotateTurret_Goal__Sequence * array);

/// Check for action/RotateTurret message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Goal__Sequence__are_equal(const turret_control__action__RotateTurret_Goal__Sequence * lhs, const turret_control__action__RotateTurret_Goal__Sequence * rhs);

/// Copy an array of action/RotateTurret messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Goal__Sequence__copy(
  const turret_control__action__RotateTurret_Goal__Sequence * input,
  turret_control__action__RotateTurret_Goal__Sequence * output);

/// Initialize action/RotateTurret message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turret_control__action__RotateTurret_Result
 * )) before or use
 * turret_control__action__RotateTurret_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Result__init(turret_control__action__RotateTurret_Result * msg);

/// Finalize action/RotateTurret message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Result__fini(turret_control__action__RotateTurret_Result * msg);

/// Create action/RotateTurret message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turret_control__action__RotateTurret_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_Result *
turret_control__action__RotateTurret_Result__create();

/// Destroy action/RotateTurret message.
/**
 * It calls
 * turret_control__action__RotateTurret_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Result__destroy(turret_control__action__RotateTurret_Result * msg);

/// Check for action/RotateTurret message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Result__are_equal(const turret_control__action__RotateTurret_Result * lhs, const turret_control__action__RotateTurret_Result * rhs);

/// Copy a action/RotateTurret message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Result__copy(
  const turret_control__action__RotateTurret_Result * input,
  turret_control__action__RotateTurret_Result * output);

/// Initialize array of action/RotateTurret messages.
/**
 * It allocates the memory for the number of elements and calls
 * turret_control__action__RotateTurret_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Result__Sequence__init(turret_control__action__RotateTurret_Result__Sequence * array, size_t size);

/// Finalize array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Result__Sequence__fini(turret_control__action__RotateTurret_Result__Sequence * array);

/// Create array of action/RotateTurret messages.
/**
 * It allocates the memory for the array and calls
 * turret_control__action__RotateTurret_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_Result__Sequence *
turret_control__action__RotateTurret_Result__Sequence__create(size_t size);

/// Destroy array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Result__Sequence__destroy(turret_control__action__RotateTurret_Result__Sequence * array);

/// Check for action/RotateTurret message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Result__Sequence__are_equal(const turret_control__action__RotateTurret_Result__Sequence * lhs, const turret_control__action__RotateTurret_Result__Sequence * rhs);

/// Copy an array of action/RotateTurret messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Result__Sequence__copy(
  const turret_control__action__RotateTurret_Result__Sequence * input,
  turret_control__action__RotateTurret_Result__Sequence * output);

/// Initialize action/RotateTurret message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turret_control__action__RotateTurret_Feedback
 * )) before or use
 * turret_control__action__RotateTurret_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Feedback__init(turret_control__action__RotateTurret_Feedback * msg);

/// Finalize action/RotateTurret message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Feedback__fini(turret_control__action__RotateTurret_Feedback * msg);

/// Create action/RotateTurret message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turret_control__action__RotateTurret_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_Feedback *
turret_control__action__RotateTurret_Feedback__create();

/// Destroy action/RotateTurret message.
/**
 * It calls
 * turret_control__action__RotateTurret_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Feedback__destroy(turret_control__action__RotateTurret_Feedback * msg);

/// Check for action/RotateTurret message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Feedback__are_equal(const turret_control__action__RotateTurret_Feedback * lhs, const turret_control__action__RotateTurret_Feedback * rhs);

/// Copy a action/RotateTurret message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Feedback__copy(
  const turret_control__action__RotateTurret_Feedback * input,
  turret_control__action__RotateTurret_Feedback * output);

/// Initialize array of action/RotateTurret messages.
/**
 * It allocates the memory for the number of elements and calls
 * turret_control__action__RotateTurret_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Feedback__Sequence__init(turret_control__action__RotateTurret_Feedback__Sequence * array, size_t size);

/// Finalize array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Feedback__Sequence__fini(turret_control__action__RotateTurret_Feedback__Sequence * array);

/// Create array of action/RotateTurret messages.
/**
 * It allocates the memory for the array and calls
 * turret_control__action__RotateTurret_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_Feedback__Sequence *
turret_control__action__RotateTurret_Feedback__Sequence__create(size_t size);

/// Destroy array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_Feedback__Sequence__destroy(turret_control__action__RotateTurret_Feedback__Sequence * array);

/// Check for action/RotateTurret message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Feedback__Sequence__are_equal(const turret_control__action__RotateTurret_Feedback__Sequence * lhs, const turret_control__action__RotateTurret_Feedback__Sequence * rhs);

/// Copy an array of action/RotateTurret messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_Feedback__Sequence__copy(
  const turret_control__action__RotateTurret_Feedback__Sequence * input,
  turret_control__action__RotateTurret_Feedback__Sequence * output);

/// Initialize action/RotateTurret message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turret_control__action__RotateTurret_SendGoal_Request
 * )) before or use
 * turret_control__action__RotateTurret_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Request__init(turret_control__action__RotateTurret_SendGoal_Request * msg);

/// Finalize action/RotateTurret message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_SendGoal_Request__fini(turret_control__action__RotateTurret_SendGoal_Request * msg);

/// Create action/RotateTurret message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turret_control__action__RotateTurret_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_SendGoal_Request *
turret_control__action__RotateTurret_SendGoal_Request__create();

/// Destroy action/RotateTurret message.
/**
 * It calls
 * turret_control__action__RotateTurret_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_SendGoal_Request__destroy(turret_control__action__RotateTurret_SendGoal_Request * msg);

/// Check for action/RotateTurret message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Request__are_equal(const turret_control__action__RotateTurret_SendGoal_Request * lhs, const turret_control__action__RotateTurret_SendGoal_Request * rhs);

/// Copy a action/RotateTurret message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Request__copy(
  const turret_control__action__RotateTurret_SendGoal_Request * input,
  turret_control__action__RotateTurret_SendGoal_Request * output);

/// Initialize array of action/RotateTurret messages.
/**
 * It allocates the memory for the number of elements and calls
 * turret_control__action__RotateTurret_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Request__Sequence__init(turret_control__action__RotateTurret_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_SendGoal_Request__Sequence__fini(turret_control__action__RotateTurret_SendGoal_Request__Sequence * array);

/// Create array of action/RotateTurret messages.
/**
 * It allocates the memory for the array and calls
 * turret_control__action__RotateTurret_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_SendGoal_Request__Sequence *
turret_control__action__RotateTurret_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_SendGoal_Request__Sequence__destroy(turret_control__action__RotateTurret_SendGoal_Request__Sequence * array);

/// Check for action/RotateTurret message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Request__Sequence__are_equal(const turret_control__action__RotateTurret_SendGoal_Request__Sequence * lhs, const turret_control__action__RotateTurret_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/RotateTurret messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Request__Sequence__copy(
  const turret_control__action__RotateTurret_SendGoal_Request__Sequence * input,
  turret_control__action__RotateTurret_SendGoal_Request__Sequence * output);

/// Initialize action/RotateTurret message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turret_control__action__RotateTurret_SendGoal_Response
 * )) before or use
 * turret_control__action__RotateTurret_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Response__init(turret_control__action__RotateTurret_SendGoal_Response * msg);

/// Finalize action/RotateTurret message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_SendGoal_Response__fini(turret_control__action__RotateTurret_SendGoal_Response * msg);

/// Create action/RotateTurret message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turret_control__action__RotateTurret_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_SendGoal_Response *
turret_control__action__RotateTurret_SendGoal_Response__create();

/// Destroy action/RotateTurret message.
/**
 * It calls
 * turret_control__action__RotateTurret_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_SendGoal_Response__destroy(turret_control__action__RotateTurret_SendGoal_Response * msg);

/// Check for action/RotateTurret message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Response__are_equal(const turret_control__action__RotateTurret_SendGoal_Response * lhs, const turret_control__action__RotateTurret_SendGoal_Response * rhs);

/// Copy a action/RotateTurret message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Response__copy(
  const turret_control__action__RotateTurret_SendGoal_Response * input,
  turret_control__action__RotateTurret_SendGoal_Response * output);

/// Initialize array of action/RotateTurret messages.
/**
 * It allocates the memory for the number of elements and calls
 * turret_control__action__RotateTurret_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Response__Sequence__init(turret_control__action__RotateTurret_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_SendGoal_Response__Sequence__fini(turret_control__action__RotateTurret_SendGoal_Response__Sequence * array);

/// Create array of action/RotateTurret messages.
/**
 * It allocates the memory for the array and calls
 * turret_control__action__RotateTurret_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_SendGoal_Response__Sequence *
turret_control__action__RotateTurret_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_SendGoal_Response__Sequence__destroy(turret_control__action__RotateTurret_SendGoal_Response__Sequence * array);

/// Check for action/RotateTurret message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Response__Sequence__are_equal(const turret_control__action__RotateTurret_SendGoal_Response__Sequence * lhs, const turret_control__action__RotateTurret_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/RotateTurret messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_SendGoal_Response__Sequence__copy(
  const turret_control__action__RotateTurret_SendGoal_Response__Sequence * input,
  turret_control__action__RotateTurret_SendGoal_Response__Sequence * output);

/// Initialize action/RotateTurret message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turret_control__action__RotateTurret_GetResult_Request
 * )) before or use
 * turret_control__action__RotateTurret_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Request__init(turret_control__action__RotateTurret_GetResult_Request * msg);

/// Finalize action/RotateTurret message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_GetResult_Request__fini(turret_control__action__RotateTurret_GetResult_Request * msg);

/// Create action/RotateTurret message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turret_control__action__RotateTurret_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_GetResult_Request *
turret_control__action__RotateTurret_GetResult_Request__create();

/// Destroy action/RotateTurret message.
/**
 * It calls
 * turret_control__action__RotateTurret_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_GetResult_Request__destroy(turret_control__action__RotateTurret_GetResult_Request * msg);

/// Check for action/RotateTurret message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Request__are_equal(const turret_control__action__RotateTurret_GetResult_Request * lhs, const turret_control__action__RotateTurret_GetResult_Request * rhs);

/// Copy a action/RotateTurret message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Request__copy(
  const turret_control__action__RotateTurret_GetResult_Request * input,
  turret_control__action__RotateTurret_GetResult_Request * output);

/// Initialize array of action/RotateTurret messages.
/**
 * It allocates the memory for the number of elements and calls
 * turret_control__action__RotateTurret_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Request__Sequence__init(turret_control__action__RotateTurret_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_GetResult_Request__Sequence__fini(turret_control__action__RotateTurret_GetResult_Request__Sequence * array);

/// Create array of action/RotateTurret messages.
/**
 * It allocates the memory for the array and calls
 * turret_control__action__RotateTurret_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_GetResult_Request__Sequence *
turret_control__action__RotateTurret_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_GetResult_Request__Sequence__destroy(turret_control__action__RotateTurret_GetResult_Request__Sequence * array);

/// Check for action/RotateTurret message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Request__Sequence__are_equal(const turret_control__action__RotateTurret_GetResult_Request__Sequence * lhs, const turret_control__action__RotateTurret_GetResult_Request__Sequence * rhs);

/// Copy an array of action/RotateTurret messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Request__Sequence__copy(
  const turret_control__action__RotateTurret_GetResult_Request__Sequence * input,
  turret_control__action__RotateTurret_GetResult_Request__Sequence * output);

/// Initialize action/RotateTurret message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turret_control__action__RotateTurret_GetResult_Response
 * )) before or use
 * turret_control__action__RotateTurret_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Response__init(turret_control__action__RotateTurret_GetResult_Response * msg);

/// Finalize action/RotateTurret message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_GetResult_Response__fini(turret_control__action__RotateTurret_GetResult_Response * msg);

/// Create action/RotateTurret message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turret_control__action__RotateTurret_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_GetResult_Response *
turret_control__action__RotateTurret_GetResult_Response__create();

/// Destroy action/RotateTurret message.
/**
 * It calls
 * turret_control__action__RotateTurret_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_GetResult_Response__destroy(turret_control__action__RotateTurret_GetResult_Response * msg);

/// Check for action/RotateTurret message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Response__are_equal(const turret_control__action__RotateTurret_GetResult_Response * lhs, const turret_control__action__RotateTurret_GetResult_Response * rhs);

/// Copy a action/RotateTurret message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Response__copy(
  const turret_control__action__RotateTurret_GetResult_Response * input,
  turret_control__action__RotateTurret_GetResult_Response * output);

/// Initialize array of action/RotateTurret messages.
/**
 * It allocates the memory for the number of elements and calls
 * turret_control__action__RotateTurret_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Response__Sequence__init(turret_control__action__RotateTurret_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_GetResult_Response__Sequence__fini(turret_control__action__RotateTurret_GetResult_Response__Sequence * array);

/// Create array of action/RotateTurret messages.
/**
 * It allocates the memory for the array and calls
 * turret_control__action__RotateTurret_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_GetResult_Response__Sequence *
turret_control__action__RotateTurret_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_GetResult_Response__Sequence__destroy(turret_control__action__RotateTurret_GetResult_Response__Sequence * array);

/// Check for action/RotateTurret message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Response__Sequence__are_equal(const turret_control__action__RotateTurret_GetResult_Response__Sequence * lhs, const turret_control__action__RotateTurret_GetResult_Response__Sequence * rhs);

/// Copy an array of action/RotateTurret messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_GetResult_Response__Sequence__copy(
  const turret_control__action__RotateTurret_GetResult_Response__Sequence * input,
  turret_control__action__RotateTurret_GetResult_Response__Sequence * output);

/// Initialize action/RotateTurret message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * turret_control__action__RotateTurret_FeedbackMessage
 * )) before or use
 * turret_control__action__RotateTurret_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_FeedbackMessage__init(turret_control__action__RotateTurret_FeedbackMessage * msg);

/// Finalize action/RotateTurret message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_FeedbackMessage__fini(turret_control__action__RotateTurret_FeedbackMessage * msg);

/// Create action/RotateTurret message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * turret_control__action__RotateTurret_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_FeedbackMessage *
turret_control__action__RotateTurret_FeedbackMessage__create();

/// Destroy action/RotateTurret message.
/**
 * It calls
 * turret_control__action__RotateTurret_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_FeedbackMessage__destroy(turret_control__action__RotateTurret_FeedbackMessage * msg);

/// Check for action/RotateTurret message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_FeedbackMessage__are_equal(const turret_control__action__RotateTurret_FeedbackMessage * lhs, const turret_control__action__RotateTurret_FeedbackMessage * rhs);

/// Copy a action/RotateTurret message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_FeedbackMessage__copy(
  const turret_control__action__RotateTurret_FeedbackMessage * input,
  turret_control__action__RotateTurret_FeedbackMessage * output);

/// Initialize array of action/RotateTurret messages.
/**
 * It allocates the memory for the number of elements and calls
 * turret_control__action__RotateTurret_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_FeedbackMessage__Sequence__init(turret_control__action__RotateTurret_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_FeedbackMessage__Sequence__fini(turret_control__action__RotateTurret_FeedbackMessage__Sequence * array);

/// Create array of action/RotateTurret messages.
/**
 * It allocates the memory for the array and calls
 * turret_control__action__RotateTurret_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
turret_control__action__RotateTurret_FeedbackMessage__Sequence *
turret_control__action__RotateTurret_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/RotateTurret messages.
/**
 * It calls
 * turret_control__action__RotateTurret_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
void
turret_control__action__RotateTurret_FeedbackMessage__Sequence__destroy(turret_control__action__RotateTurret_FeedbackMessage__Sequence * array);

/// Check for action/RotateTurret message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_FeedbackMessage__Sequence__are_equal(const turret_control__action__RotateTurret_FeedbackMessage__Sequence * lhs, const turret_control__action__RotateTurret_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/RotateTurret messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_turret_control
bool
turret_control__action__RotateTurret_FeedbackMessage__Sequence__copy(
  const turret_control__action__RotateTurret_FeedbackMessage__Sequence * input,
  turret_control__action__RotateTurret_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TURRET_CONTROL__ACTION__DETAIL__ROTATE_TURRET__FUNCTIONS_H_
