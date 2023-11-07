// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from detector:msg/MyCustomMsg.idl
// generated code does not contain a copyright notice
#include "detector/msg/detail/my_custom_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `frame_id`
// Member `object_classes`
#include "rosidl_runtime_c/string_functions.h"
// Member `object_scores`
// Member `object_bounding_boxes`
// Member `object_positions`
// Member `object_orientations`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
detector__msg__MyCustomMsg__init(detector__msg__MyCustomMsg * msg)
{
  if (!msg) {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__init(&msg->frame_id)) {
    detector__msg__MyCustomMsg__fini(msg);
    return false;
  }
  // object_classes
  if (!rosidl_runtime_c__String__Sequence__init(&msg->object_classes, 0)) {
    detector__msg__MyCustomMsg__fini(msg);
    return false;
  }
  // object_scores
  if (!rosidl_runtime_c__float__Sequence__init(&msg->object_scores, 0)) {
    detector__msg__MyCustomMsg__fini(msg);
    return false;
  }
  // object_bounding_boxes
  if (!rosidl_runtime_c__float__Sequence__init(&msg->object_bounding_boxes, 0)) {
    detector__msg__MyCustomMsg__fini(msg);
    return false;
  }
  // object_positions
  if (!rosidl_runtime_c__float__Sequence__init(&msg->object_positions, 0)) {
    detector__msg__MyCustomMsg__fini(msg);
    return false;
  }
  // object_orientations
  if (!rosidl_runtime_c__float__Sequence__init(&msg->object_orientations, 0)) {
    detector__msg__MyCustomMsg__fini(msg);
    return false;
  }
  return true;
}

void
detector__msg__MyCustomMsg__fini(detector__msg__MyCustomMsg * msg)
{
  if (!msg) {
    return;
  }
  // frame_id
  rosidl_runtime_c__String__fini(&msg->frame_id);
  // object_classes
  rosidl_runtime_c__String__Sequence__fini(&msg->object_classes);
  // object_scores
  rosidl_runtime_c__float__Sequence__fini(&msg->object_scores);
  // object_bounding_boxes
  rosidl_runtime_c__float__Sequence__fini(&msg->object_bounding_boxes);
  // object_positions
  rosidl_runtime_c__float__Sequence__fini(&msg->object_positions);
  // object_orientations
  rosidl_runtime_c__float__Sequence__fini(&msg->object_orientations);
}

bool
detector__msg__MyCustomMsg__are_equal(const detector__msg__MyCustomMsg * lhs, const detector__msg__MyCustomMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->frame_id), &(rhs->frame_id)))
  {
    return false;
  }
  // object_classes
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->object_classes), &(rhs->object_classes)))
  {
    return false;
  }
  // object_scores
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->object_scores), &(rhs->object_scores)))
  {
    return false;
  }
  // object_bounding_boxes
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->object_bounding_boxes), &(rhs->object_bounding_boxes)))
  {
    return false;
  }
  // object_positions
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->object_positions), &(rhs->object_positions)))
  {
    return false;
  }
  // object_orientations
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->object_orientations), &(rhs->object_orientations)))
  {
    return false;
  }
  return true;
}

bool
detector__msg__MyCustomMsg__copy(
  const detector__msg__MyCustomMsg * input,
  detector__msg__MyCustomMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->frame_id), &(output->frame_id)))
  {
    return false;
  }
  // object_classes
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->object_classes), &(output->object_classes)))
  {
    return false;
  }
  // object_scores
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->object_scores), &(output->object_scores)))
  {
    return false;
  }
  // object_bounding_boxes
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->object_bounding_boxes), &(output->object_bounding_boxes)))
  {
    return false;
  }
  // object_positions
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->object_positions), &(output->object_positions)))
  {
    return false;
  }
  // object_orientations
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->object_orientations), &(output->object_orientations)))
  {
    return false;
  }
  return true;
}

detector__msg__MyCustomMsg *
detector__msg__MyCustomMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  detector__msg__MyCustomMsg * msg = (detector__msg__MyCustomMsg *)allocator.allocate(sizeof(detector__msg__MyCustomMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(detector__msg__MyCustomMsg));
  bool success = detector__msg__MyCustomMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
detector__msg__MyCustomMsg__destroy(detector__msg__MyCustomMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    detector__msg__MyCustomMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
detector__msg__MyCustomMsg__Sequence__init(detector__msg__MyCustomMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  detector__msg__MyCustomMsg * data = NULL;

  if (size) {
    data = (detector__msg__MyCustomMsg *)allocator.zero_allocate(size, sizeof(detector__msg__MyCustomMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = detector__msg__MyCustomMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        detector__msg__MyCustomMsg__fini(&data[i - 1]);
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
detector__msg__MyCustomMsg__Sequence__fini(detector__msg__MyCustomMsg__Sequence * array)
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
      detector__msg__MyCustomMsg__fini(&array->data[i]);
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

detector__msg__MyCustomMsg__Sequence *
detector__msg__MyCustomMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  detector__msg__MyCustomMsg__Sequence * array = (detector__msg__MyCustomMsg__Sequence *)allocator.allocate(sizeof(detector__msg__MyCustomMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = detector__msg__MyCustomMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
detector__msg__MyCustomMsg__Sequence__destroy(detector__msg__MyCustomMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    detector__msg__MyCustomMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
detector__msg__MyCustomMsg__Sequence__are_equal(const detector__msg__MyCustomMsg__Sequence * lhs, const detector__msg__MyCustomMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!detector__msg__MyCustomMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
detector__msg__MyCustomMsg__Sequence__copy(
  const detector__msg__MyCustomMsg__Sequence * input,
  detector__msg__MyCustomMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(detector__msg__MyCustomMsg);
    detector__msg__MyCustomMsg * data =
      (detector__msg__MyCustomMsg *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!detector__msg__MyCustomMsg__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          detector__msg__MyCustomMsg__fini(&data[i]);
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
    if (!detector__msg__MyCustomMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
