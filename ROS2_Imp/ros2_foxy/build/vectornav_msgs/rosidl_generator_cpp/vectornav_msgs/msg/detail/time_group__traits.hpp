// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vectornav_msgs:msg/TimeGroup.idl
// generated code does not contain a copyright notice

#ifndef VECTORNAV_MSGS__MSG__DETAIL__TIME_GROUP__TRAITS_HPP_
#define VECTORNAV_MSGS__MSG__DETAIL__TIME_GROUP__TRAITS_HPP_

#include "vectornav_msgs/msg/detail/time_group__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'timeutc'
#include "vectornav_msgs/msg/detail/time_utc__traits.hpp"
// Member 'timestatus'
#include "vectornav_msgs/msg/detail/time_status__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::msg::TimeGroup>()
{
  return "vectornav_msgs::msg::TimeGroup";
}

template<>
inline const char * name<vectornav_msgs::msg::TimeGroup>()
{
  return "vectornav_msgs/msg/TimeGroup";
}

template<>
struct has_fixed_size<vectornav_msgs::msg::TimeGroup>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<vectornav_msgs::msg::TimeStatus>::value && has_fixed_size<vectornav_msgs::msg::TimeUTC>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::msg::TimeGroup>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<vectornav_msgs::msg::TimeStatus>::value && has_bounded_size<vectornav_msgs::msg::TimeUTC>::value> {};

template<>
struct is_message<vectornav_msgs::msg::TimeGroup>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VECTORNAV_MSGS__MSG__DETAIL__TIME_GROUP__TRAITS_HPP_
