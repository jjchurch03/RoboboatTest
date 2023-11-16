// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from detector:msg/MyCustomMsgDetector.idl
// generated code does not contain a copyright notice

#ifndef DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "detector/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "detector/msg/detail/my_custom_msg_detector__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace detector
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detector
cdr_serialize(
  const detector::msg::MyCustomMsgDetector & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detector
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  detector::msg::MyCustomMsgDetector & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detector
get_serialized_size(
  const detector::msg::MyCustomMsgDetector & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detector
max_serialized_size_MyCustomMsgDetector(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace detector

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_detector
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, detector, msg, MyCustomMsgDetector)();

#ifdef __cplusplus
}
#endif

#endif  // DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
