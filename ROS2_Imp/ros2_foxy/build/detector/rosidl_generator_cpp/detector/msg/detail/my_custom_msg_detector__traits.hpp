// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from detector:msg/MyCustomMsgDetector.idl
// generated code does not contain a copyright notice

#ifndef DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__TRAITS_HPP_
#define DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__TRAITS_HPP_

#include "detector/msg/detail/my_custom_msg_detector__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<detector::msg::MyCustomMsgDetector>()
{
  return "detector::msg::MyCustomMsgDetector";
}

template<>
inline const char * name<detector::msg::MyCustomMsgDetector>()
{
  return "detector/msg/MyCustomMsgDetector";
}

template<>
struct has_fixed_size<detector::msg::MyCustomMsgDetector>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<detector::msg::MyCustomMsgDetector>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<detector::msg::MyCustomMsgDetector>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__TRAITS_HPP_
