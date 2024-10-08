// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vectornav_msgs:action/MagCal.idl
// generated code does not contain a copyright notice
#include "vectornav_msgs/action/detail/mag_cal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vectornav_msgs__action__MagCal_Goal__init(vectornav_msgs__action__MagCal_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
vectornav_msgs__action__MagCal_Goal__fini(vectornav_msgs__action__MagCal_Goal * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
vectornav_msgs__action__MagCal_Goal__are_equal(const vectornav_msgs__action__MagCal_Goal * lhs, const vectornav_msgs__action__MagCal_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_Goal__copy(
  const vectornav_msgs__action__MagCal_Goal * input,
  vectornav_msgs__action__MagCal_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

vectornav_msgs__action__MagCal_Goal *
vectornav_msgs__action__MagCal_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_Goal * msg = (vectornav_msgs__action__MagCal_Goal *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vectornav_msgs__action__MagCal_Goal));
  bool success = vectornav_msgs__action__MagCal_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vectornav_msgs__action__MagCal_Goal__destroy(vectornav_msgs__action__MagCal_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vectornav_msgs__action__MagCal_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vectornav_msgs__action__MagCal_Goal__Sequence__init(vectornav_msgs__action__MagCal_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_Goal * data = NULL;

  if (size) {
    data = (vectornav_msgs__action__MagCal_Goal *)allocator.zero_allocate(size, sizeof(vectornav_msgs__action__MagCal_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vectornav_msgs__action__MagCal_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vectornav_msgs__action__MagCal_Goal__fini(&data[i - 1]);
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
vectornav_msgs__action__MagCal_Goal__Sequence__fini(vectornav_msgs__action__MagCal_Goal__Sequence * array)
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
      vectornav_msgs__action__MagCal_Goal__fini(&array->data[i]);
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

vectornav_msgs__action__MagCal_Goal__Sequence *
vectornav_msgs__action__MagCal_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_Goal__Sequence * array = (vectornav_msgs__action__MagCal_Goal__Sequence *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vectornav_msgs__action__MagCal_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vectornav_msgs__action__MagCal_Goal__Sequence__destroy(vectornav_msgs__action__MagCal_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vectornav_msgs__action__MagCal_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vectornav_msgs__action__MagCal_Goal__Sequence__are_equal(const vectornav_msgs__action__MagCal_Goal__Sequence * lhs, const vectornav_msgs__action__MagCal_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vectornav_msgs__action__MagCal_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_Goal__Sequence__copy(
  const vectornav_msgs__action__MagCal_Goal__Sequence * input,
  vectornav_msgs__action__MagCal_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vectornav_msgs__action__MagCal_Goal);
    vectornav_msgs__action__MagCal_Goal * data =
      (vectornav_msgs__action__MagCal_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vectornav_msgs__action__MagCal_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vectornav_msgs__action__MagCal_Goal__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vectornav_msgs__action__MagCal_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
vectornav_msgs__action__MagCal_Result__init(vectornav_msgs__action__MagCal_Result * msg)
{
  if (!msg) {
    return false;
  }
  // avg_dev
  // calib
  return true;
}

void
vectornav_msgs__action__MagCal_Result__fini(vectornav_msgs__action__MagCal_Result * msg)
{
  if (!msg) {
    return;
  }
  // avg_dev
  // calib
}

bool
vectornav_msgs__action__MagCal_Result__are_equal(const vectornav_msgs__action__MagCal_Result * lhs, const vectornav_msgs__action__MagCal_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // avg_dev
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->avg_dev[i] != rhs->avg_dev[i]) {
      return false;
    }
  }
  // calib
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->calib[i] != rhs->calib[i]) {
      return false;
    }
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_Result__copy(
  const vectornav_msgs__action__MagCal_Result * input,
  vectornav_msgs__action__MagCal_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // avg_dev
  for (size_t i = 0; i < 12; ++i) {
    output->avg_dev[i] = input->avg_dev[i];
  }
  // calib
  for (size_t i = 0; i < 12; ++i) {
    output->calib[i] = input->calib[i];
  }
  return true;
}

vectornav_msgs__action__MagCal_Result *
vectornav_msgs__action__MagCal_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_Result * msg = (vectornav_msgs__action__MagCal_Result *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vectornav_msgs__action__MagCal_Result));
  bool success = vectornav_msgs__action__MagCal_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vectornav_msgs__action__MagCal_Result__destroy(vectornav_msgs__action__MagCal_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vectornav_msgs__action__MagCal_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vectornav_msgs__action__MagCal_Result__Sequence__init(vectornav_msgs__action__MagCal_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_Result * data = NULL;

  if (size) {
    data = (vectornav_msgs__action__MagCal_Result *)allocator.zero_allocate(size, sizeof(vectornav_msgs__action__MagCal_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vectornav_msgs__action__MagCal_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vectornav_msgs__action__MagCal_Result__fini(&data[i - 1]);
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
vectornav_msgs__action__MagCal_Result__Sequence__fini(vectornav_msgs__action__MagCal_Result__Sequence * array)
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
      vectornav_msgs__action__MagCal_Result__fini(&array->data[i]);
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

vectornav_msgs__action__MagCal_Result__Sequence *
vectornav_msgs__action__MagCal_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_Result__Sequence * array = (vectornav_msgs__action__MagCal_Result__Sequence *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vectornav_msgs__action__MagCal_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vectornav_msgs__action__MagCal_Result__Sequence__destroy(vectornav_msgs__action__MagCal_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vectornav_msgs__action__MagCal_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vectornav_msgs__action__MagCal_Result__Sequence__are_equal(const vectornav_msgs__action__MagCal_Result__Sequence * lhs, const vectornav_msgs__action__MagCal_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vectornav_msgs__action__MagCal_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_Result__Sequence__copy(
  const vectornav_msgs__action__MagCal_Result__Sequence * input,
  vectornav_msgs__action__MagCal_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vectornav_msgs__action__MagCal_Result);
    vectornav_msgs__action__MagCal_Result * data =
      (vectornav_msgs__action__MagCal_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vectornav_msgs__action__MagCal_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vectornav_msgs__action__MagCal_Result__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vectornav_msgs__action__MagCal_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
vectornav_msgs__action__MagCal_Feedback__init(vectornav_msgs__action__MagCal_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // curr_avg_dev
  // curr_calib
  // samples
  return true;
}

void
vectornav_msgs__action__MagCal_Feedback__fini(vectornav_msgs__action__MagCal_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // curr_avg_dev
  // curr_calib
  // samples
}

bool
vectornav_msgs__action__MagCal_Feedback__are_equal(const vectornav_msgs__action__MagCal_Feedback * lhs, const vectornav_msgs__action__MagCal_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // curr_avg_dev
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->curr_avg_dev[i] != rhs->curr_avg_dev[i]) {
      return false;
    }
  }
  // curr_calib
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->curr_calib[i] != rhs->curr_calib[i]) {
      return false;
    }
  }
  // samples
  if (lhs->samples != rhs->samples) {
    return false;
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_Feedback__copy(
  const vectornav_msgs__action__MagCal_Feedback * input,
  vectornav_msgs__action__MagCal_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // curr_avg_dev
  for (size_t i = 0; i < 12; ++i) {
    output->curr_avg_dev[i] = input->curr_avg_dev[i];
  }
  // curr_calib
  for (size_t i = 0; i < 12; ++i) {
    output->curr_calib[i] = input->curr_calib[i];
  }
  // samples
  output->samples = input->samples;
  return true;
}

vectornav_msgs__action__MagCal_Feedback *
vectornav_msgs__action__MagCal_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_Feedback * msg = (vectornav_msgs__action__MagCal_Feedback *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vectornav_msgs__action__MagCal_Feedback));
  bool success = vectornav_msgs__action__MagCal_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vectornav_msgs__action__MagCal_Feedback__destroy(vectornav_msgs__action__MagCal_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vectornav_msgs__action__MagCal_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vectornav_msgs__action__MagCal_Feedback__Sequence__init(vectornav_msgs__action__MagCal_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_Feedback * data = NULL;

  if (size) {
    data = (vectornav_msgs__action__MagCal_Feedback *)allocator.zero_allocate(size, sizeof(vectornav_msgs__action__MagCal_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vectornav_msgs__action__MagCal_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vectornav_msgs__action__MagCal_Feedback__fini(&data[i - 1]);
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
vectornav_msgs__action__MagCal_Feedback__Sequence__fini(vectornav_msgs__action__MagCal_Feedback__Sequence * array)
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
      vectornav_msgs__action__MagCal_Feedback__fini(&array->data[i]);
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

vectornav_msgs__action__MagCal_Feedback__Sequence *
vectornav_msgs__action__MagCal_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_Feedback__Sequence * array = (vectornav_msgs__action__MagCal_Feedback__Sequence *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vectornav_msgs__action__MagCal_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vectornav_msgs__action__MagCal_Feedback__Sequence__destroy(vectornav_msgs__action__MagCal_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vectornav_msgs__action__MagCal_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vectornav_msgs__action__MagCal_Feedback__Sequence__are_equal(const vectornav_msgs__action__MagCal_Feedback__Sequence * lhs, const vectornav_msgs__action__MagCal_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vectornav_msgs__action__MagCal_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_Feedback__Sequence__copy(
  const vectornav_msgs__action__MagCal_Feedback__Sequence * input,
  vectornav_msgs__action__MagCal_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vectornav_msgs__action__MagCal_Feedback);
    vectornav_msgs__action__MagCal_Feedback * data =
      (vectornav_msgs__action__MagCal_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vectornav_msgs__action__MagCal_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vectornav_msgs__action__MagCal_Feedback__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vectornav_msgs__action__MagCal_Feedback__copy(
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
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"

bool
vectornav_msgs__action__MagCal_SendGoal_Request__init(vectornav_msgs__action__MagCal_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    vectornav_msgs__action__MagCal_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!vectornav_msgs__action__MagCal_Goal__init(&msg->goal)) {
    vectornav_msgs__action__MagCal_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
vectornav_msgs__action__MagCal_SendGoal_Request__fini(vectornav_msgs__action__MagCal_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  vectornav_msgs__action__MagCal_Goal__fini(&msg->goal);
}

bool
vectornav_msgs__action__MagCal_SendGoal_Request__are_equal(const vectornav_msgs__action__MagCal_SendGoal_Request * lhs, const vectornav_msgs__action__MagCal_SendGoal_Request * rhs)
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
  if (!vectornav_msgs__action__MagCal_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_SendGoal_Request__copy(
  const vectornav_msgs__action__MagCal_SendGoal_Request * input,
  vectornav_msgs__action__MagCal_SendGoal_Request * output)
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
  if (!vectornav_msgs__action__MagCal_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

vectornav_msgs__action__MagCal_SendGoal_Request *
vectornav_msgs__action__MagCal_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_SendGoal_Request * msg = (vectornav_msgs__action__MagCal_SendGoal_Request *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vectornav_msgs__action__MagCal_SendGoal_Request));
  bool success = vectornav_msgs__action__MagCal_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vectornav_msgs__action__MagCal_SendGoal_Request__destroy(vectornav_msgs__action__MagCal_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vectornav_msgs__action__MagCal_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vectornav_msgs__action__MagCal_SendGoal_Request__Sequence__init(vectornav_msgs__action__MagCal_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_SendGoal_Request * data = NULL;

  if (size) {
    data = (vectornav_msgs__action__MagCal_SendGoal_Request *)allocator.zero_allocate(size, sizeof(vectornav_msgs__action__MagCal_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vectornav_msgs__action__MagCal_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vectornav_msgs__action__MagCal_SendGoal_Request__fini(&data[i - 1]);
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
vectornav_msgs__action__MagCal_SendGoal_Request__Sequence__fini(vectornav_msgs__action__MagCal_SendGoal_Request__Sequence * array)
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
      vectornav_msgs__action__MagCal_SendGoal_Request__fini(&array->data[i]);
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

vectornav_msgs__action__MagCal_SendGoal_Request__Sequence *
vectornav_msgs__action__MagCal_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_SendGoal_Request__Sequence * array = (vectornav_msgs__action__MagCal_SendGoal_Request__Sequence *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vectornav_msgs__action__MagCal_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vectornav_msgs__action__MagCal_SendGoal_Request__Sequence__destroy(vectornav_msgs__action__MagCal_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vectornav_msgs__action__MagCal_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vectornav_msgs__action__MagCal_SendGoal_Request__Sequence__are_equal(const vectornav_msgs__action__MagCal_SendGoal_Request__Sequence * lhs, const vectornav_msgs__action__MagCal_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vectornav_msgs__action__MagCal_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_SendGoal_Request__Sequence__copy(
  const vectornav_msgs__action__MagCal_SendGoal_Request__Sequence * input,
  vectornav_msgs__action__MagCal_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vectornav_msgs__action__MagCal_SendGoal_Request);
    vectornav_msgs__action__MagCal_SendGoal_Request * data =
      (vectornav_msgs__action__MagCal_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vectornav_msgs__action__MagCal_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vectornav_msgs__action__MagCal_SendGoal_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vectornav_msgs__action__MagCal_SendGoal_Request__copy(
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
vectornav_msgs__action__MagCal_SendGoal_Response__init(vectornav_msgs__action__MagCal_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    vectornav_msgs__action__MagCal_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
vectornav_msgs__action__MagCal_SendGoal_Response__fini(vectornav_msgs__action__MagCal_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
vectornav_msgs__action__MagCal_SendGoal_Response__are_equal(const vectornav_msgs__action__MagCal_SendGoal_Response * lhs, const vectornav_msgs__action__MagCal_SendGoal_Response * rhs)
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
vectornav_msgs__action__MagCal_SendGoal_Response__copy(
  const vectornav_msgs__action__MagCal_SendGoal_Response * input,
  vectornav_msgs__action__MagCal_SendGoal_Response * output)
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

vectornav_msgs__action__MagCal_SendGoal_Response *
vectornav_msgs__action__MagCal_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_SendGoal_Response * msg = (vectornav_msgs__action__MagCal_SendGoal_Response *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vectornav_msgs__action__MagCal_SendGoal_Response));
  bool success = vectornav_msgs__action__MagCal_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vectornav_msgs__action__MagCal_SendGoal_Response__destroy(vectornav_msgs__action__MagCal_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vectornav_msgs__action__MagCal_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vectornav_msgs__action__MagCal_SendGoal_Response__Sequence__init(vectornav_msgs__action__MagCal_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_SendGoal_Response * data = NULL;

  if (size) {
    data = (vectornav_msgs__action__MagCal_SendGoal_Response *)allocator.zero_allocate(size, sizeof(vectornav_msgs__action__MagCal_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vectornav_msgs__action__MagCal_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vectornav_msgs__action__MagCal_SendGoal_Response__fini(&data[i - 1]);
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
vectornav_msgs__action__MagCal_SendGoal_Response__Sequence__fini(vectornav_msgs__action__MagCal_SendGoal_Response__Sequence * array)
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
      vectornav_msgs__action__MagCal_SendGoal_Response__fini(&array->data[i]);
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

vectornav_msgs__action__MagCal_SendGoal_Response__Sequence *
vectornav_msgs__action__MagCal_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_SendGoal_Response__Sequence * array = (vectornav_msgs__action__MagCal_SendGoal_Response__Sequence *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vectornav_msgs__action__MagCal_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vectornav_msgs__action__MagCal_SendGoal_Response__Sequence__destroy(vectornav_msgs__action__MagCal_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vectornav_msgs__action__MagCal_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vectornav_msgs__action__MagCal_SendGoal_Response__Sequence__are_equal(const vectornav_msgs__action__MagCal_SendGoal_Response__Sequence * lhs, const vectornav_msgs__action__MagCal_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vectornav_msgs__action__MagCal_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_SendGoal_Response__Sequence__copy(
  const vectornav_msgs__action__MagCal_SendGoal_Response__Sequence * input,
  vectornav_msgs__action__MagCal_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vectornav_msgs__action__MagCal_SendGoal_Response);
    vectornav_msgs__action__MagCal_SendGoal_Response * data =
      (vectornav_msgs__action__MagCal_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vectornav_msgs__action__MagCal_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vectornav_msgs__action__MagCal_SendGoal_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vectornav_msgs__action__MagCal_SendGoal_Response__copy(
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
vectornav_msgs__action__MagCal_GetResult_Request__init(vectornav_msgs__action__MagCal_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    vectornav_msgs__action__MagCal_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
vectornav_msgs__action__MagCal_GetResult_Request__fini(vectornav_msgs__action__MagCal_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
vectornav_msgs__action__MagCal_GetResult_Request__are_equal(const vectornav_msgs__action__MagCal_GetResult_Request * lhs, const vectornav_msgs__action__MagCal_GetResult_Request * rhs)
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
vectornav_msgs__action__MagCal_GetResult_Request__copy(
  const vectornav_msgs__action__MagCal_GetResult_Request * input,
  vectornav_msgs__action__MagCal_GetResult_Request * output)
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

vectornav_msgs__action__MagCal_GetResult_Request *
vectornav_msgs__action__MagCal_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_GetResult_Request * msg = (vectornav_msgs__action__MagCal_GetResult_Request *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vectornav_msgs__action__MagCal_GetResult_Request));
  bool success = vectornav_msgs__action__MagCal_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vectornav_msgs__action__MagCal_GetResult_Request__destroy(vectornav_msgs__action__MagCal_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vectornav_msgs__action__MagCal_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vectornav_msgs__action__MagCal_GetResult_Request__Sequence__init(vectornav_msgs__action__MagCal_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_GetResult_Request * data = NULL;

  if (size) {
    data = (vectornav_msgs__action__MagCal_GetResult_Request *)allocator.zero_allocate(size, sizeof(vectornav_msgs__action__MagCal_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vectornav_msgs__action__MagCal_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vectornav_msgs__action__MagCal_GetResult_Request__fini(&data[i - 1]);
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
vectornav_msgs__action__MagCal_GetResult_Request__Sequence__fini(vectornav_msgs__action__MagCal_GetResult_Request__Sequence * array)
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
      vectornav_msgs__action__MagCal_GetResult_Request__fini(&array->data[i]);
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

vectornav_msgs__action__MagCal_GetResult_Request__Sequence *
vectornav_msgs__action__MagCal_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_GetResult_Request__Sequence * array = (vectornav_msgs__action__MagCal_GetResult_Request__Sequence *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vectornav_msgs__action__MagCal_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vectornav_msgs__action__MagCal_GetResult_Request__Sequence__destroy(vectornav_msgs__action__MagCal_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vectornav_msgs__action__MagCal_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vectornav_msgs__action__MagCal_GetResult_Request__Sequence__are_equal(const vectornav_msgs__action__MagCal_GetResult_Request__Sequence * lhs, const vectornav_msgs__action__MagCal_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vectornav_msgs__action__MagCal_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_GetResult_Request__Sequence__copy(
  const vectornav_msgs__action__MagCal_GetResult_Request__Sequence * input,
  vectornav_msgs__action__MagCal_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vectornav_msgs__action__MagCal_GetResult_Request);
    vectornav_msgs__action__MagCal_GetResult_Request * data =
      (vectornav_msgs__action__MagCal_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vectornav_msgs__action__MagCal_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vectornav_msgs__action__MagCal_GetResult_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vectornav_msgs__action__MagCal_GetResult_Request__copy(
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
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"

bool
vectornav_msgs__action__MagCal_GetResult_Response__init(vectornav_msgs__action__MagCal_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!vectornav_msgs__action__MagCal_Result__init(&msg->result)) {
    vectornav_msgs__action__MagCal_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
vectornav_msgs__action__MagCal_GetResult_Response__fini(vectornav_msgs__action__MagCal_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  vectornav_msgs__action__MagCal_Result__fini(&msg->result);
}

bool
vectornav_msgs__action__MagCal_GetResult_Response__are_equal(const vectornav_msgs__action__MagCal_GetResult_Response * lhs, const vectornav_msgs__action__MagCal_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!vectornav_msgs__action__MagCal_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_GetResult_Response__copy(
  const vectornav_msgs__action__MagCal_GetResult_Response * input,
  vectornav_msgs__action__MagCal_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!vectornav_msgs__action__MagCal_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

vectornav_msgs__action__MagCal_GetResult_Response *
vectornav_msgs__action__MagCal_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_GetResult_Response * msg = (vectornav_msgs__action__MagCal_GetResult_Response *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vectornav_msgs__action__MagCal_GetResult_Response));
  bool success = vectornav_msgs__action__MagCal_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vectornav_msgs__action__MagCal_GetResult_Response__destroy(vectornav_msgs__action__MagCal_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vectornav_msgs__action__MagCal_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vectornav_msgs__action__MagCal_GetResult_Response__Sequence__init(vectornav_msgs__action__MagCal_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_GetResult_Response * data = NULL;

  if (size) {
    data = (vectornav_msgs__action__MagCal_GetResult_Response *)allocator.zero_allocate(size, sizeof(vectornav_msgs__action__MagCal_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vectornav_msgs__action__MagCal_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vectornav_msgs__action__MagCal_GetResult_Response__fini(&data[i - 1]);
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
vectornav_msgs__action__MagCal_GetResult_Response__Sequence__fini(vectornav_msgs__action__MagCal_GetResult_Response__Sequence * array)
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
      vectornav_msgs__action__MagCal_GetResult_Response__fini(&array->data[i]);
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

vectornav_msgs__action__MagCal_GetResult_Response__Sequence *
vectornav_msgs__action__MagCal_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_GetResult_Response__Sequence * array = (vectornav_msgs__action__MagCal_GetResult_Response__Sequence *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vectornav_msgs__action__MagCal_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vectornav_msgs__action__MagCal_GetResult_Response__Sequence__destroy(vectornav_msgs__action__MagCal_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vectornav_msgs__action__MagCal_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vectornav_msgs__action__MagCal_GetResult_Response__Sequence__are_equal(const vectornav_msgs__action__MagCal_GetResult_Response__Sequence * lhs, const vectornav_msgs__action__MagCal_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vectornav_msgs__action__MagCal_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_GetResult_Response__Sequence__copy(
  const vectornav_msgs__action__MagCal_GetResult_Response__Sequence * input,
  vectornav_msgs__action__MagCal_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vectornav_msgs__action__MagCal_GetResult_Response);
    vectornav_msgs__action__MagCal_GetResult_Response * data =
      (vectornav_msgs__action__MagCal_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vectornav_msgs__action__MagCal_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vectornav_msgs__action__MagCal_GetResult_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vectornav_msgs__action__MagCal_GetResult_Response__copy(
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
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"

bool
vectornav_msgs__action__MagCal_FeedbackMessage__init(vectornav_msgs__action__MagCal_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    vectornav_msgs__action__MagCal_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!vectornav_msgs__action__MagCal_Feedback__init(&msg->feedback)) {
    vectornav_msgs__action__MagCal_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
vectornav_msgs__action__MagCal_FeedbackMessage__fini(vectornav_msgs__action__MagCal_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  vectornav_msgs__action__MagCal_Feedback__fini(&msg->feedback);
}

bool
vectornav_msgs__action__MagCal_FeedbackMessage__are_equal(const vectornav_msgs__action__MagCal_FeedbackMessage * lhs, const vectornav_msgs__action__MagCal_FeedbackMessage * rhs)
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
  if (!vectornav_msgs__action__MagCal_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_FeedbackMessage__copy(
  const vectornav_msgs__action__MagCal_FeedbackMessage * input,
  vectornav_msgs__action__MagCal_FeedbackMessage * output)
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
  if (!vectornav_msgs__action__MagCal_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

vectornav_msgs__action__MagCal_FeedbackMessage *
vectornav_msgs__action__MagCal_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_FeedbackMessage * msg = (vectornav_msgs__action__MagCal_FeedbackMessage *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vectornav_msgs__action__MagCal_FeedbackMessage));
  bool success = vectornav_msgs__action__MagCal_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vectornav_msgs__action__MagCal_FeedbackMessage__destroy(vectornav_msgs__action__MagCal_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vectornav_msgs__action__MagCal_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vectornav_msgs__action__MagCal_FeedbackMessage__Sequence__init(vectornav_msgs__action__MagCal_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_FeedbackMessage * data = NULL;

  if (size) {
    data = (vectornav_msgs__action__MagCal_FeedbackMessage *)allocator.zero_allocate(size, sizeof(vectornav_msgs__action__MagCal_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vectornav_msgs__action__MagCal_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vectornav_msgs__action__MagCal_FeedbackMessage__fini(&data[i - 1]);
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
vectornav_msgs__action__MagCal_FeedbackMessage__Sequence__fini(vectornav_msgs__action__MagCal_FeedbackMessage__Sequence * array)
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
      vectornav_msgs__action__MagCal_FeedbackMessage__fini(&array->data[i]);
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

vectornav_msgs__action__MagCal_FeedbackMessage__Sequence *
vectornav_msgs__action__MagCal_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vectornav_msgs__action__MagCal_FeedbackMessage__Sequence * array = (vectornav_msgs__action__MagCal_FeedbackMessage__Sequence *)allocator.allocate(sizeof(vectornav_msgs__action__MagCal_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vectornav_msgs__action__MagCal_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vectornav_msgs__action__MagCal_FeedbackMessage__Sequence__destroy(vectornav_msgs__action__MagCal_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vectornav_msgs__action__MagCal_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vectornav_msgs__action__MagCal_FeedbackMessage__Sequence__are_equal(const vectornav_msgs__action__MagCal_FeedbackMessage__Sequence * lhs, const vectornav_msgs__action__MagCal_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vectornav_msgs__action__MagCal_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vectornav_msgs__action__MagCal_FeedbackMessage__Sequence__copy(
  const vectornav_msgs__action__MagCal_FeedbackMessage__Sequence * input,
  vectornav_msgs__action__MagCal_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vectornav_msgs__action__MagCal_FeedbackMessage);
    vectornav_msgs__action__MagCal_FeedbackMessage * data =
      (vectornav_msgs__action__MagCal_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vectornav_msgs__action__MagCal_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          vectornav_msgs__action__MagCal_FeedbackMessage__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vectornav_msgs__action__MagCal_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
