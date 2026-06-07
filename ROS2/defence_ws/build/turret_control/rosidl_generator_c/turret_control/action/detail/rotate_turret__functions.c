// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turret_control:action/RotateTurret.idl
// generated code does not contain a copyright notice
#include "turret_control/action/detail/rotate_turret__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
turret_control__action__RotateTurret_Goal__init(turret_control__action__RotateTurret_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // target_angle
  return true;
}

void
turret_control__action__RotateTurret_Goal__fini(turret_control__action__RotateTurret_Goal * msg)
{
  if (!msg) {
    return;
  }
  // target_angle
}

bool
turret_control__action__RotateTurret_Goal__are_equal(const turret_control__action__RotateTurret_Goal * lhs, const turret_control__action__RotateTurret_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_angle
  if (lhs->target_angle != rhs->target_angle) {
    return false;
  }
  return true;
}

bool
turret_control__action__RotateTurret_Goal__copy(
  const turret_control__action__RotateTurret_Goal * input,
  turret_control__action__RotateTurret_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // target_angle
  output->target_angle = input->target_angle;
  return true;
}

turret_control__action__RotateTurret_Goal *
turret_control__action__RotateTurret_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_Goal * msg = (turret_control__action__RotateTurret_Goal *)allocator.allocate(sizeof(turret_control__action__RotateTurret_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turret_control__action__RotateTurret_Goal));
  bool success = turret_control__action__RotateTurret_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turret_control__action__RotateTurret_Goal__destroy(turret_control__action__RotateTurret_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turret_control__action__RotateTurret_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turret_control__action__RotateTurret_Goal__Sequence__init(turret_control__action__RotateTurret_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_Goal * data = NULL;

  if (size) {
    data = (turret_control__action__RotateTurret_Goal *)allocator.zero_allocate(size, sizeof(turret_control__action__RotateTurret_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turret_control__action__RotateTurret_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turret_control__action__RotateTurret_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turret_control__action__RotateTurret_Goal__Sequence__fini(turret_control__action__RotateTurret_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turret_control__action__RotateTurret_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turret_control__action__RotateTurret_Goal__Sequence *
turret_control__action__RotateTurret_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_Goal__Sequence * array = (turret_control__action__RotateTurret_Goal__Sequence *)allocator.allocate(sizeof(turret_control__action__RotateTurret_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turret_control__action__RotateTurret_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turret_control__action__RotateTurret_Goal__Sequence__destroy(turret_control__action__RotateTurret_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turret_control__action__RotateTurret_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turret_control__action__RotateTurret_Goal__Sequence__are_equal(const turret_control__action__RotateTurret_Goal__Sequence * lhs, const turret_control__action__RotateTurret_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turret_control__action__RotateTurret_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turret_control__action__RotateTurret_Goal__Sequence__copy(
  const turret_control__action__RotateTurret_Goal__Sequence * input,
  turret_control__action__RotateTurret_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turret_control__action__RotateTurret_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turret_control__action__RotateTurret_Goal * data =
      (turret_control__action__RotateTurret_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turret_control__action__RotateTurret_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turret_control__action__RotateTurret_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turret_control__action__RotateTurret_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result_message`
#include "rosidl_runtime_c/string_functions.h"

bool
turret_control__action__RotateTurret_Result__init(turret_control__action__RotateTurret_Result * msg)
{
  if (!msg) {
    return false;
  }
  // result_message
  if (!rosidl_runtime_c__String__init(&msg->result_message)) {
    turret_control__action__RotateTurret_Result__fini(msg);
    return false;
  }
  return true;
}

void
turret_control__action__RotateTurret_Result__fini(turret_control__action__RotateTurret_Result * msg)
{
  if (!msg) {
    return;
  }
  // result_message
  rosidl_runtime_c__String__fini(&msg->result_message);
}

bool
turret_control__action__RotateTurret_Result__are_equal(const turret_control__action__RotateTurret_Result * lhs, const turret_control__action__RotateTurret_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result_message), &(rhs->result_message)))
  {
    return false;
  }
  return true;
}

bool
turret_control__action__RotateTurret_Result__copy(
  const turret_control__action__RotateTurret_Result * input,
  turret_control__action__RotateTurret_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // result_message
  if (!rosidl_runtime_c__String__copy(
      &(input->result_message), &(output->result_message)))
  {
    return false;
  }
  return true;
}

turret_control__action__RotateTurret_Result *
turret_control__action__RotateTurret_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_Result * msg = (turret_control__action__RotateTurret_Result *)allocator.allocate(sizeof(turret_control__action__RotateTurret_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turret_control__action__RotateTurret_Result));
  bool success = turret_control__action__RotateTurret_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turret_control__action__RotateTurret_Result__destroy(turret_control__action__RotateTurret_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turret_control__action__RotateTurret_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turret_control__action__RotateTurret_Result__Sequence__init(turret_control__action__RotateTurret_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_Result * data = NULL;

  if (size) {
    data = (turret_control__action__RotateTurret_Result *)allocator.zero_allocate(size, sizeof(turret_control__action__RotateTurret_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turret_control__action__RotateTurret_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turret_control__action__RotateTurret_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turret_control__action__RotateTurret_Result__Sequence__fini(turret_control__action__RotateTurret_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turret_control__action__RotateTurret_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turret_control__action__RotateTurret_Result__Sequence *
turret_control__action__RotateTurret_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_Result__Sequence * array = (turret_control__action__RotateTurret_Result__Sequence *)allocator.allocate(sizeof(turret_control__action__RotateTurret_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turret_control__action__RotateTurret_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turret_control__action__RotateTurret_Result__Sequence__destroy(turret_control__action__RotateTurret_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turret_control__action__RotateTurret_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turret_control__action__RotateTurret_Result__Sequence__are_equal(const turret_control__action__RotateTurret_Result__Sequence * lhs, const turret_control__action__RotateTurret_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turret_control__action__RotateTurret_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turret_control__action__RotateTurret_Result__Sequence__copy(
  const turret_control__action__RotateTurret_Result__Sequence * input,
  turret_control__action__RotateTurret_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turret_control__action__RotateTurret_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turret_control__action__RotateTurret_Result * data =
      (turret_control__action__RotateTurret_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turret_control__action__RotateTurret_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turret_control__action__RotateTurret_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turret_control__action__RotateTurret_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
turret_control__action__RotateTurret_Feedback__init(turret_control__action__RotateTurret_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // current_angle
  return true;
}

void
turret_control__action__RotateTurret_Feedback__fini(turret_control__action__RotateTurret_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // current_angle
}

bool
turret_control__action__RotateTurret_Feedback__are_equal(const turret_control__action__RotateTurret_Feedback * lhs, const turret_control__action__RotateTurret_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_angle
  if (lhs->current_angle != rhs->current_angle) {
    return false;
  }
  return true;
}

bool
turret_control__action__RotateTurret_Feedback__copy(
  const turret_control__action__RotateTurret_Feedback * input,
  turret_control__action__RotateTurret_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // current_angle
  output->current_angle = input->current_angle;
  return true;
}

turret_control__action__RotateTurret_Feedback *
turret_control__action__RotateTurret_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_Feedback * msg = (turret_control__action__RotateTurret_Feedback *)allocator.allocate(sizeof(turret_control__action__RotateTurret_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turret_control__action__RotateTurret_Feedback));
  bool success = turret_control__action__RotateTurret_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turret_control__action__RotateTurret_Feedback__destroy(turret_control__action__RotateTurret_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turret_control__action__RotateTurret_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turret_control__action__RotateTurret_Feedback__Sequence__init(turret_control__action__RotateTurret_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_Feedback * data = NULL;

  if (size) {
    data = (turret_control__action__RotateTurret_Feedback *)allocator.zero_allocate(size, sizeof(turret_control__action__RotateTurret_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turret_control__action__RotateTurret_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turret_control__action__RotateTurret_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turret_control__action__RotateTurret_Feedback__Sequence__fini(turret_control__action__RotateTurret_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turret_control__action__RotateTurret_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turret_control__action__RotateTurret_Feedback__Sequence *
turret_control__action__RotateTurret_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_Feedback__Sequence * array = (turret_control__action__RotateTurret_Feedback__Sequence *)allocator.allocate(sizeof(turret_control__action__RotateTurret_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turret_control__action__RotateTurret_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turret_control__action__RotateTurret_Feedback__Sequence__destroy(turret_control__action__RotateTurret_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turret_control__action__RotateTurret_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turret_control__action__RotateTurret_Feedback__Sequence__are_equal(const turret_control__action__RotateTurret_Feedback__Sequence * lhs, const turret_control__action__RotateTurret_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turret_control__action__RotateTurret_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turret_control__action__RotateTurret_Feedback__Sequence__copy(
  const turret_control__action__RotateTurret_Feedback__Sequence * input,
  turret_control__action__RotateTurret_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turret_control__action__RotateTurret_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turret_control__action__RotateTurret_Feedback * data =
      (turret_control__action__RotateTurret_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turret_control__action__RotateTurret_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turret_control__action__RotateTurret_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turret_control__action__RotateTurret_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "turret_control/action/detail/rotate_turret__functions.h"

bool
turret_control__action__RotateTurret_SendGoal_Request__init(turret_control__action__RotateTurret_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    turret_control__action__RotateTurret_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!turret_control__action__RotateTurret_Goal__init(&msg->goal)) {
    turret_control__action__RotateTurret_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
turret_control__action__RotateTurret_SendGoal_Request__fini(turret_control__action__RotateTurret_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  turret_control__action__RotateTurret_Goal__fini(&msg->goal);
}

bool
turret_control__action__RotateTurret_SendGoal_Request__are_equal(const turret_control__action__RotateTurret_SendGoal_Request * lhs, const turret_control__action__RotateTurret_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!turret_control__action__RotateTurret_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
turret_control__action__RotateTurret_SendGoal_Request__copy(
  const turret_control__action__RotateTurret_SendGoal_Request * input,
  turret_control__action__RotateTurret_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!turret_control__action__RotateTurret_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

turret_control__action__RotateTurret_SendGoal_Request *
turret_control__action__RotateTurret_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_SendGoal_Request * msg = (turret_control__action__RotateTurret_SendGoal_Request *)allocator.allocate(sizeof(turret_control__action__RotateTurret_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turret_control__action__RotateTurret_SendGoal_Request));
  bool success = turret_control__action__RotateTurret_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turret_control__action__RotateTurret_SendGoal_Request__destroy(turret_control__action__RotateTurret_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turret_control__action__RotateTurret_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turret_control__action__RotateTurret_SendGoal_Request__Sequence__init(turret_control__action__RotateTurret_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_SendGoal_Request * data = NULL;

  if (size) {
    data = (turret_control__action__RotateTurret_SendGoal_Request *)allocator.zero_allocate(size, sizeof(turret_control__action__RotateTurret_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turret_control__action__RotateTurret_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turret_control__action__RotateTurret_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turret_control__action__RotateTurret_SendGoal_Request__Sequence__fini(turret_control__action__RotateTurret_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turret_control__action__RotateTurret_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turret_control__action__RotateTurret_SendGoal_Request__Sequence *
turret_control__action__RotateTurret_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_SendGoal_Request__Sequence * array = (turret_control__action__RotateTurret_SendGoal_Request__Sequence *)allocator.allocate(sizeof(turret_control__action__RotateTurret_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turret_control__action__RotateTurret_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turret_control__action__RotateTurret_SendGoal_Request__Sequence__destroy(turret_control__action__RotateTurret_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turret_control__action__RotateTurret_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turret_control__action__RotateTurret_SendGoal_Request__Sequence__are_equal(const turret_control__action__RotateTurret_SendGoal_Request__Sequence * lhs, const turret_control__action__RotateTurret_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turret_control__action__RotateTurret_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turret_control__action__RotateTurret_SendGoal_Request__Sequence__copy(
  const turret_control__action__RotateTurret_SendGoal_Request__Sequence * input,
  turret_control__action__RotateTurret_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turret_control__action__RotateTurret_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turret_control__action__RotateTurret_SendGoal_Request * data =
      (turret_control__action__RotateTurret_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turret_control__action__RotateTurret_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turret_control__action__RotateTurret_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turret_control__action__RotateTurret_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
turret_control__action__RotateTurret_SendGoal_Response__init(turret_control__action__RotateTurret_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    turret_control__action__RotateTurret_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
turret_control__action__RotateTurret_SendGoal_Response__fini(turret_control__action__RotateTurret_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
turret_control__action__RotateTurret_SendGoal_Response__are_equal(const turret_control__action__RotateTurret_SendGoal_Response * lhs, const turret_control__action__RotateTurret_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
turret_control__action__RotateTurret_SendGoal_Response__copy(
  const turret_control__action__RotateTurret_SendGoal_Response * input,
  turret_control__action__RotateTurret_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

turret_control__action__RotateTurret_SendGoal_Response *
turret_control__action__RotateTurret_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_SendGoal_Response * msg = (turret_control__action__RotateTurret_SendGoal_Response *)allocator.allocate(sizeof(turret_control__action__RotateTurret_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turret_control__action__RotateTurret_SendGoal_Response));
  bool success = turret_control__action__RotateTurret_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turret_control__action__RotateTurret_SendGoal_Response__destroy(turret_control__action__RotateTurret_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turret_control__action__RotateTurret_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turret_control__action__RotateTurret_SendGoal_Response__Sequence__init(turret_control__action__RotateTurret_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_SendGoal_Response * data = NULL;

  if (size) {
    data = (turret_control__action__RotateTurret_SendGoal_Response *)allocator.zero_allocate(size, sizeof(turret_control__action__RotateTurret_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turret_control__action__RotateTurret_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turret_control__action__RotateTurret_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turret_control__action__RotateTurret_SendGoal_Response__Sequence__fini(turret_control__action__RotateTurret_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turret_control__action__RotateTurret_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turret_control__action__RotateTurret_SendGoal_Response__Sequence *
turret_control__action__RotateTurret_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_SendGoal_Response__Sequence * array = (turret_control__action__RotateTurret_SendGoal_Response__Sequence *)allocator.allocate(sizeof(turret_control__action__RotateTurret_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turret_control__action__RotateTurret_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turret_control__action__RotateTurret_SendGoal_Response__Sequence__destroy(turret_control__action__RotateTurret_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turret_control__action__RotateTurret_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turret_control__action__RotateTurret_SendGoal_Response__Sequence__are_equal(const turret_control__action__RotateTurret_SendGoal_Response__Sequence * lhs, const turret_control__action__RotateTurret_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turret_control__action__RotateTurret_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turret_control__action__RotateTurret_SendGoal_Response__Sequence__copy(
  const turret_control__action__RotateTurret_SendGoal_Response__Sequence * input,
  turret_control__action__RotateTurret_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turret_control__action__RotateTurret_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turret_control__action__RotateTurret_SendGoal_Response * data =
      (turret_control__action__RotateTurret_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turret_control__action__RotateTurret_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turret_control__action__RotateTurret_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turret_control__action__RotateTurret_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
turret_control__action__RotateTurret_GetResult_Request__init(turret_control__action__RotateTurret_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    turret_control__action__RotateTurret_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
turret_control__action__RotateTurret_GetResult_Request__fini(turret_control__action__RotateTurret_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
turret_control__action__RotateTurret_GetResult_Request__are_equal(const turret_control__action__RotateTurret_GetResult_Request * lhs, const turret_control__action__RotateTurret_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
turret_control__action__RotateTurret_GetResult_Request__copy(
  const turret_control__action__RotateTurret_GetResult_Request * input,
  turret_control__action__RotateTurret_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

turret_control__action__RotateTurret_GetResult_Request *
turret_control__action__RotateTurret_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_GetResult_Request * msg = (turret_control__action__RotateTurret_GetResult_Request *)allocator.allocate(sizeof(turret_control__action__RotateTurret_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turret_control__action__RotateTurret_GetResult_Request));
  bool success = turret_control__action__RotateTurret_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turret_control__action__RotateTurret_GetResult_Request__destroy(turret_control__action__RotateTurret_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turret_control__action__RotateTurret_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turret_control__action__RotateTurret_GetResult_Request__Sequence__init(turret_control__action__RotateTurret_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_GetResult_Request * data = NULL;

  if (size) {
    data = (turret_control__action__RotateTurret_GetResult_Request *)allocator.zero_allocate(size, sizeof(turret_control__action__RotateTurret_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turret_control__action__RotateTurret_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turret_control__action__RotateTurret_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turret_control__action__RotateTurret_GetResult_Request__Sequence__fini(turret_control__action__RotateTurret_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turret_control__action__RotateTurret_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turret_control__action__RotateTurret_GetResult_Request__Sequence *
turret_control__action__RotateTurret_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_GetResult_Request__Sequence * array = (turret_control__action__RotateTurret_GetResult_Request__Sequence *)allocator.allocate(sizeof(turret_control__action__RotateTurret_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turret_control__action__RotateTurret_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turret_control__action__RotateTurret_GetResult_Request__Sequence__destroy(turret_control__action__RotateTurret_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turret_control__action__RotateTurret_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turret_control__action__RotateTurret_GetResult_Request__Sequence__are_equal(const turret_control__action__RotateTurret_GetResult_Request__Sequence * lhs, const turret_control__action__RotateTurret_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turret_control__action__RotateTurret_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turret_control__action__RotateTurret_GetResult_Request__Sequence__copy(
  const turret_control__action__RotateTurret_GetResult_Request__Sequence * input,
  turret_control__action__RotateTurret_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turret_control__action__RotateTurret_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turret_control__action__RotateTurret_GetResult_Request * data =
      (turret_control__action__RotateTurret_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turret_control__action__RotateTurret_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turret_control__action__RotateTurret_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turret_control__action__RotateTurret_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "turret_control/action/detail/rotate_turret__functions.h"

bool
turret_control__action__RotateTurret_GetResult_Response__init(turret_control__action__RotateTurret_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!turret_control__action__RotateTurret_Result__init(&msg->result)) {
    turret_control__action__RotateTurret_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
turret_control__action__RotateTurret_GetResult_Response__fini(turret_control__action__RotateTurret_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  turret_control__action__RotateTurret_Result__fini(&msg->result);
}

bool
turret_control__action__RotateTurret_GetResult_Response__are_equal(const turret_control__action__RotateTurret_GetResult_Response * lhs, const turret_control__action__RotateTurret_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!turret_control__action__RotateTurret_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
turret_control__action__RotateTurret_GetResult_Response__copy(
  const turret_control__action__RotateTurret_GetResult_Response * input,
  turret_control__action__RotateTurret_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!turret_control__action__RotateTurret_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

turret_control__action__RotateTurret_GetResult_Response *
turret_control__action__RotateTurret_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_GetResult_Response * msg = (turret_control__action__RotateTurret_GetResult_Response *)allocator.allocate(sizeof(turret_control__action__RotateTurret_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turret_control__action__RotateTurret_GetResult_Response));
  bool success = turret_control__action__RotateTurret_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turret_control__action__RotateTurret_GetResult_Response__destroy(turret_control__action__RotateTurret_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turret_control__action__RotateTurret_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turret_control__action__RotateTurret_GetResult_Response__Sequence__init(turret_control__action__RotateTurret_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_GetResult_Response * data = NULL;

  if (size) {
    data = (turret_control__action__RotateTurret_GetResult_Response *)allocator.zero_allocate(size, sizeof(turret_control__action__RotateTurret_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turret_control__action__RotateTurret_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turret_control__action__RotateTurret_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turret_control__action__RotateTurret_GetResult_Response__Sequence__fini(turret_control__action__RotateTurret_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turret_control__action__RotateTurret_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turret_control__action__RotateTurret_GetResult_Response__Sequence *
turret_control__action__RotateTurret_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_GetResult_Response__Sequence * array = (turret_control__action__RotateTurret_GetResult_Response__Sequence *)allocator.allocate(sizeof(turret_control__action__RotateTurret_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turret_control__action__RotateTurret_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turret_control__action__RotateTurret_GetResult_Response__Sequence__destroy(turret_control__action__RotateTurret_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turret_control__action__RotateTurret_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turret_control__action__RotateTurret_GetResult_Response__Sequence__are_equal(const turret_control__action__RotateTurret_GetResult_Response__Sequence * lhs, const turret_control__action__RotateTurret_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turret_control__action__RotateTurret_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turret_control__action__RotateTurret_GetResult_Response__Sequence__copy(
  const turret_control__action__RotateTurret_GetResult_Response__Sequence * input,
  turret_control__action__RotateTurret_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turret_control__action__RotateTurret_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turret_control__action__RotateTurret_GetResult_Response * data =
      (turret_control__action__RotateTurret_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turret_control__action__RotateTurret_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turret_control__action__RotateTurret_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turret_control__action__RotateTurret_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "turret_control/action/detail/rotate_turret__functions.h"

bool
turret_control__action__RotateTurret_FeedbackMessage__init(turret_control__action__RotateTurret_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    turret_control__action__RotateTurret_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!turret_control__action__RotateTurret_Feedback__init(&msg->feedback)) {
    turret_control__action__RotateTurret_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
turret_control__action__RotateTurret_FeedbackMessage__fini(turret_control__action__RotateTurret_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  turret_control__action__RotateTurret_Feedback__fini(&msg->feedback);
}

bool
turret_control__action__RotateTurret_FeedbackMessage__are_equal(const turret_control__action__RotateTurret_FeedbackMessage * lhs, const turret_control__action__RotateTurret_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!turret_control__action__RotateTurret_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
turret_control__action__RotateTurret_FeedbackMessage__copy(
  const turret_control__action__RotateTurret_FeedbackMessage * input,
  turret_control__action__RotateTurret_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!turret_control__action__RotateTurret_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

turret_control__action__RotateTurret_FeedbackMessage *
turret_control__action__RotateTurret_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_FeedbackMessage * msg = (turret_control__action__RotateTurret_FeedbackMessage *)allocator.allocate(sizeof(turret_control__action__RotateTurret_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turret_control__action__RotateTurret_FeedbackMessage));
  bool success = turret_control__action__RotateTurret_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turret_control__action__RotateTurret_FeedbackMessage__destroy(turret_control__action__RotateTurret_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turret_control__action__RotateTurret_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turret_control__action__RotateTurret_FeedbackMessage__Sequence__init(turret_control__action__RotateTurret_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_FeedbackMessage * data = NULL;

  if (size) {
    data = (turret_control__action__RotateTurret_FeedbackMessage *)allocator.zero_allocate(size, sizeof(turret_control__action__RotateTurret_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turret_control__action__RotateTurret_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turret_control__action__RotateTurret_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turret_control__action__RotateTurret_FeedbackMessage__Sequence__fini(turret_control__action__RotateTurret_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turret_control__action__RotateTurret_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turret_control__action__RotateTurret_FeedbackMessage__Sequence *
turret_control__action__RotateTurret_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turret_control__action__RotateTurret_FeedbackMessage__Sequence * array = (turret_control__action__RotateTurret_FeedbackMessage__Sequence *)allocator.allocate(sizeof(turret_control__action__RotateTurret_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turret_control__action__RotateTurret_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turret_control__action__RotateTurret_FeedbackMessage__Sequence__destroy(turret_control__action__RotateTurret_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turret_control__action__RotateTurret_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turret_control__action__RotateTurret_FeedbackMessage__Sequence__are_equal(const turret_control__action__RotateTurret_FeedbackMessage__Sequence * lhs, const turret_control__action__RotateTurret_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turret_control__action__RotateTurret_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turret_control__action__RotateTurret_FeedbackMessage__Sequence__copy(
  const turret_control__action__RotateTurret_FeedbackMessage__Sequence * input,
  turret_control__action__RotateTurret_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turret_control__action__RotateTurret_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turret_control__action__RotateTurret_FeedbackMessage * data =
      (turret_control__action__RotateTurret_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turret_control__action__RotateTurret_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turret_control__action__RotateTurret_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turret_control__action__RotateTurret_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
