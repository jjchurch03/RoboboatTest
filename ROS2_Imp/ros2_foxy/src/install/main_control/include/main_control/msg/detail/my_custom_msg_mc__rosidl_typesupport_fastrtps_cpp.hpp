// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from main_control:msg/MyCustomMsgMC.idl
// generated code does not contain a copyright notice

#ifndef MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG_MC__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG_MC__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "main_control/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "main_control/msg/detail/my_custom_msg_mc__struct.hpp"

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

namespace main_control
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_main_control
cdr_serialize(
  const main_control::msg::MyCustomMsgMC & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_main_control
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  main_control::msg::MyCustomMsgMC & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_main_control
get_serialized_size(
  const main_control::msg::MyCustomMsgMC & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_main_control
max_serialized_size_MyCustomMsgMC(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace main_control

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_main_control
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, main_control, msg, MyCustomMsgMC)();

#ifdef __cplusplus
}
#endif

#endif  // MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG_MC__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
