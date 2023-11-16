// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from detector:msg/MyCustomMsgDetector.idl
// generated code does not contain a copyright notice
#include "detector/msg/detail/my_custom_msg_detector__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "detector/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "detector/msg/detail/my_custom_msg_detector__struct.h"
#include "detector/msg/detail/my_custom_msg_detector__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // object_bounding_boxes, object_orientations, object_positions, object_scores
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // object_bounding_boxes, object_orientations, object_positions, object_scores
#include "rosidl_runtime_c/string.h"  // frame_id, object_classes
#include "rosidl_runtime_c/string_functions.h"  // frame_id, object_classes

// forward declare type support functions


using _MyCustomMsgDetector__ros_msg_type = detector__msg__MyCustomMsgDetector;

static bool _MyCustomMsgDetector__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MyCustomMsgDetector__ros_msg_type * ros_message = static_cast<const _MyCustomMsgDetector__ros_msg_type *>(untyped_ros_message);
  // Field name: frame_id
  {
    const rosidl_runtime_c__String * str = &ros_message->frame_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: object_classes
  {
    size_t size = ros_message->object_classes.size;
    auto array_ptr = ros_message->object_classes.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  // Field name: object_scores
  {
    size_t size = ros_message->object_scores.size;
    auto array_ptr = ros_message->object_scores.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: object_bounding_boxes
  {
    size_t size = ros_message->object_bounding_boxes.size;
    auto array_ptr = ros_message->object_bounding_boxes.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: object_positions
  {
    size_t size = ros_message->object_positions.size;
    auto array_ptr = ros_message->object_positions.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: object_orientations
  {
    size_t size = ros_message->object_orientations.size;
    auto array_ptr = ros_message->object_orientations.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _MyCustomMsgDetector__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MyCustomMsgDetector__ros_msg_type * ros_message = static_cast<_MyCustomMsgDetector__ros_msg_type *>(untyped_ros_message);
  // Field name: frame_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->frame_id.data) {
      rosidl_runtime_c__String__init(&ros_message->frame_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->frame_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'frame_id'\n");
      return false;
    }
  }

  // Field name: object_classes
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->object_classes.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->object_classes);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->object_classes, size)) {
      return "failed to create array for field 'object_classes'";
    }
    auto array_ptr = ros_message->object_classes.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'object_classes'\n");
        return false;
      }
    }
  }

  // Field name: object_scores
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->object_scores.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->object_scores);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->object_scores, size)) {
      return "failed to create array for field 'object_scores'";
    }
    auto array_ptr = ros_message->object_scores.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: object_bounding_boxes
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->object_bounding_boxes.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->object_bounding_boxes);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->object_bounding_boxes, size)) {
      return "failed to create array for field 'object_bounding_boxes'";
    }
    auto array_ptr = ros_message->object_bounding_boxes.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: object_positions
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->object_positions.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->object_positions);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->object_positions, size)) {
      return "failed to create array for field 'object_positions'";
    }
    auto array_ptr = ros_message->object_positions.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: object_orientations
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->object_orientations.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->object_orientations);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->object_orientations, size)) {
      return "failed to create array for field 'object_orientations'";
    }
    auto array_ptr = ros_message->object_orientations.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_detector
size_t get_serialized_size_detector__msg__MyCustomMsgDetector(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MyCustomMsgDetector__ros_msg_type * ros_message = static_cast<const _MyCustomMsgDetector__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->frame_id.size + 1);
  // field.name object_classes
  {
    size_t array_size = ros_message->object_classes.size;
    auto array_ptr = ros_message->object_classes.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name object_scores
  {
    size_t array_size = ros_message->object_scores.size;
    auto array_ptr = ros_message->object_scores.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name object_bounding_boxes
  {
    size_t array_size = ros_message->object_bounding_boxes.size;
    auto array_ptr = ros_message->object_bounding_boxes.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name object_positions
  {
    size_t array_size = ros_message->object_positions.size;
    auto array_ptr = ros_message->object_positions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name object_orientations
  {
    size_t array_size = ros_message->object_orientations.size;
    auto array_ptr = ros_message->object_orientations.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MyCustomMsgDetector__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_detector__msg__MyCustomMsgDetector(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_detector
size_t max_serialized_size_detector__msg__MyCustomMsgDetector(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: frame_id
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: object_classes
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: object_scores
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: object_bounding_boxes
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: object_positions
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: object_orientations
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _MyCustomMsgDetector__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_detector__msg__MyCustomMsgDetector(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MyCustomMsgDetector = {
  "detector::msg",
  "MyCustomMsgDetector",
  _MyCustomMsgDetector__cdr_serialize,
  _MyCustomMsgDetector__cdr_deserialize,
  _MyCustomMsgDetector__get_serialized_size,
  _MyCustomMsgDetector__max_serialized_size
};

static rosidl_message_type_support_t _MyCustomMsgDetector__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MyCustomMsgDetector,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, detector, msg, MyCustomMsgDetector)() {
  return &_MyCustomMsgDetector__type_support;
}

#if defined(__cplusplus)
}
#endif
