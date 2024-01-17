// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vectornav_msgs:msg/InsGroup.idl
// generated code does not contain a copyright notice

#ifndef VECTORNAV_MSGS__MSG__DETAIL__INS_GROUP__TRAITS_HPP_
#define VECTORNAV_MSGS__MSG__DETAIL__INS_GROUP__TRAITS_HPP_

#include "vectornav_msgs/msg/detail/ins_group__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'insstatus'
#include "vectornav_msgs/msg/detail/ins_status__traits.hpp"
// Member 'poslla'
// Member 'posecef'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'velbody'
// Member 'velned'
// Member 'velecef'
// Member 'magecef'
// Member 'accelecef'
// Member 'linearaccelecef'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::msg::InsGroup>()
{
  return "vectornav_msgs::msg::InsGroup";
}

template<>
inline const char * name<vectornav_msgs::msg::InsGroup>()
{
  return "vectornav_msgs/msg/InsGroup";
}

template<>
struct has_fixed_size<vectornav_msgs::msg::InsGroup>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<vectornav_msgs::msg::InsStatus>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::msg::InsGroup>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<vectornav_msgs::msg::InsStatus>::value> {};

template<>
struct is_message<vectornav_msgs::msg::InsGroup>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VECTORNAV_MSGS__MSG__DETAIL__INS_GROUP__TRAITS_HPP_
