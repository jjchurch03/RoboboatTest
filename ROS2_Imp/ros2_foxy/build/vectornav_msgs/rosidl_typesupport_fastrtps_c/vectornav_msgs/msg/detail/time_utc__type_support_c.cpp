// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vectornav_msgs:msg/TimeUTC.idl
// generated code does not contain a copyright notice
#include "vectornav_msgs/msg/detail/time_utc__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vectornav_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vectornav_msgs/msg/detail/time_utc__struct.h"
#include "vectornav_msgs/msg/detail/time_utc__functions.h"
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


// forward declare type support functions


using _TimeUTC__ros_msg_type = vectornav_msgs__msg__TimeUTC;

static bool _TimeUTC__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TimeUTC__ros_msg_type * ros_message = static_cast<const _TimeUTC__ros_msg_type *>(untyped_ros_message);
  // Field name: year
  {
    cdr << ros_message->year;
  }

  // Field name: month
  {
    cdr << ros_message->month;
  }

  // Field name: day
  {
    cdr << ros_message->day;
  }

  // Field name: hour
  {
    cdr << ros_message->hour;
  }

  // Field name: min
  {
    cdr << ros_message->min;
  }

  // Field name: sec
  {
    cdr << ros_message->sec;
  }

  // Field name: ms
  {
    cdr << ros_message->ms;
  }

  return true;
}

static bool _TimeUTC__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TimeUTC__ros_msg_type * ros_message = static_cast<_TimeUTC__ros_msg_type *>(untyped_ros_message);
  // Field name: year
  {
    cdr >> ros_message->year;
  }

  // Field name: month
  {
    cdr >> ros_message->month;
  }

  // Field name: day
  {
    cdr >> ros_message->day;
  }

  // Field name: hour
  {
    cdr >> ros_message->hour;
  }

  // Field name: min
  {
    cdr >> ros_message->min;
  }

  // Field name: sec
  {
    cdr >> ros_message->sec;
  }

  // Field name: ms
  {
    cdr >> ros_message->ms;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vectornav_msgs
size_t get_serialized_size_vectornav_msgs__msg__TimeUTC(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TimeUTC__ros_msg_type * ros_message = static_cast<const _TimeUTC__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name year
  {
    size_t item_size = sizeof(ros_message->year);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name month
  {
    size_t item_size = sizeof(ros_message->month);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name day
  {
    size_t item_size = sizeof(ros_message->day);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hour
  {
    size_t item_size = sizeof(ros_message->hour);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name min
  {
    size_t item_size = sizeof(ros_message->min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sec
  {
    size_t item_size = sizeof(ros_message->sec);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ms
  {
    size_t item_size = sizeof(ros_message->ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TimeUTC__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vectornav_msgs__msg__TimeUTC(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vectornav_msgs
size_t max_serialized_size_vectornav_msgs__msg__TimeUTC(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: year
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: month
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: day
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hour
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: min
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: sec
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ms
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _TimeUTC__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_vectornav_msgs__msg__TimeUTC(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_TimeUTC = {
  "vectornav_msgs::msg",
  "TimeUTC",
  _TimeUTC__cdr_serialize,
  _TimeUTC__cdr_deserialize,
  _TimeUTC__get_serialized_size,
  _TimeUTC__max_serialized_size
};

static rosidl_message_type_support_t _TimeUTC__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TimeUTC,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vectornav_msgs, msg, TimeUTC)() {
  return &_TimeUTC__type_support;
}

#if defined(__cplusplus)
}
#endif
