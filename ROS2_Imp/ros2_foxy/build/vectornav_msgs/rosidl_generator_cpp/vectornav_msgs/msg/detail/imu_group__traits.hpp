// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vectornav_msgs:msg/ImuGroup.idl
// generated code does not contain a copyright notice

#ifndef VECTORNAV_MSGS__MSG__DETAIL__IMU_GROUP__TRAITS_HPP_
#define VECTORNAV_MSGS__MSG__DETAIL__IMU_GROUP__TRAITS_HPP_

#include "vectornav_msgs/msg/detail/imu_group__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'uncompmag'
// Member 'uncompaccel'
// Member 'uncompgyro'
// Member 'deltatheta_dtheta'
// Member 'deltavel'
// Member 'mag'
// Member 'accel'
// Member 'angularrate'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::msg::ImuGroup>()
{
  return "vectornav_msgs::msg::ImuGroup";
}

template<>
inline const char * name<vectornav_msgs::msg::ImuGroup>()
{
  return "vectornav_msgs/msg/ImuGroup";
}

template<>
struct has_fixed_size<vectornav_msgs::msg::ImuGroup>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::msg::ImuGroup>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<vectornav_msgs::msg::ImuGroup>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VECTORNAV_MSGS__MSG__DETAIL__IMU_GROUP__TRAITS_HPP_
