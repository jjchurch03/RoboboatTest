// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from main_control:msg/MyCustomMsg.idl
// generated code does not contain a copyright notice

#ifndef MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__TRAITS_HPP_
#define MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__TRAITS_HPP_

#include "main_control/msg/detail/my_custom_msg__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<main_control::msg::MyCustomMsg>()
{
  return "main_control::msg::MyCustomMsg";
}

template<>
inline const char * name<main_control::msg::MyCustomMsg>()
{
  return "main_control/msg/MyCustomMsg";
}

template<>
struct has_fixed_size<main_control::msg::MyCustomMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<main_control::msg::MyCustomMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<main_control::msg::MyCustomMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__TRAITS_HPP_
