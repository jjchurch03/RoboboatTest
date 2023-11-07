// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from main_control:msg/MyCustomMsg.idl
// generated code does not contain a copyright notice

#ifndef MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__STRUCT_H_
#define MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'frame_id'
// Member 'object_classes'
#include "rosidl_runtime_c/string.h"
// Member 'object_scores'
// Member 'object_bounding_boxes'
// Member 'object_positions'
// Member 'object_orientations'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/MyCustomMsg in the package main_control.
typedef struct main_control__msg__MyCustomMsg
{
  rosidl_runtime_c__String frame_id;
  rosidl_runtime_c__String__Sequence object_classes;
  rosidl_runtime_c__float__Sequence object_scores;
  rosidl_runtime_c__float__Sequence object_bounding_boxes;
  rosidl_runtime_c__float__Sequence object_positions;
  rosidl_runtime_c__float__Sequence object_orientations;
} main_control__msg__MyCustomMsg;

// Struct for a sequence of main_control__msg__MyCustomMsg.
typedef struct main_control__msg__MyCustomMsg__Sequence
{
  main_control__msg__MyCustomMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} main_control__msg__MyCustomMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__STRUCT_H_
