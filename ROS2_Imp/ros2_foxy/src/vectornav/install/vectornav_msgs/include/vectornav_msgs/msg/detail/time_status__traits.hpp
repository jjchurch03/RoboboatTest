// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vectornav_msgs:msg/TimeStatus.idl
// generated code does not contain a copyright notice

#ifndef VECTORNAV_MSGS__MSG__DETAIL__TIME_STATUS__TRAITS_HPP_
#define VECTORNAV_MSGS__MSG__DETAIL__TIME_STATUS__TRAITS_HPP_

#include "vectornav_msgs/msg/detail/time_status__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::msg::TimeStatus>()
{
  return "vectornav_msgs::msg::TimeStatus";
}

template<>
inline const char * name<vectornav_msgs::msg::TimeStatus>()
{
  return "vectornav_msgs/msg/TimeStatus";
}

template<>
struct has_fixed_size<vectornav_msgs::msg::TimeStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vectornav_msgs::msg::TimeStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vectornav_msgs::msg::TimeStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VECTORNAV_MSGS__MSG__DETAIL__TIME_STATUS__TRAITS_HPP_
