// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from detector:msg/YOLOv5helper.idl
// generated code does not contain a copyright notice

#ifndef DETECTOR__MSG__DETAIL__YOL_OV5HELPER__STRUCT_H_
#define DETECTOR__MSG__DETAIL__YOL_OV5HELPER__STRUCT_H_

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

// Struct defined in msg/YOLOv5helper in the package detector.
typedef struct detector__msg__YOLOv5helper
{
  rosidl_runtime_c__String frame_id;
  rosidl_runtime_c__String__Sequence object_classes;
  rosidl_runtime_c__float__Sequence object_scores;
  rosidl_runtime_c__float__Sequence object_bounding_boxes;
  rosidl_runtime_c__float__Sequence object_positions;
  rosidl_runtime_c__float__Sequence object_orientations;
} detector__msg__YOLOv5helper;

// Struct for a sequence of detector__msg__YOLOv5helper.
typedef struct detector__msg__YOLOv5helper__Sequence
{
  detector__msg__YOLOv5helper * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} detector__msg__YOLOv5helper__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DETECTOR__MSG__DETAIL__YOL_OV5HELPER__STRUCT_H_
