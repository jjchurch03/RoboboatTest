// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vectornav_msgs:msg/CommonGroup.idl
// generated code does not contain a copyright notice

#ifndef VECTORNAV_MSGS__MSG__DETAIL__COMMON_GROUP__TRAITS_HPP_
#define VECTORNAV_MSGS__MSG__DETAIL__COMMON_GROUP__TRAITS_HPP_

#include "vectornav_msgs/msg/detail/common_group__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'yawpitchroll'
// Member 'angularrate'
// Member 'velocity'
// Member 'accel'
// Member 'imu_accel'
// Member 'imu_rate'
// Member 'magpres_mag'
// Member 'deltatheta_dtheta'
// Member 'deltatheta_dvel'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'insstatus'
#include "vectornav_msgs/msg/detail/ins_status__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::msg::CommonGroup>()
{
  return "vectornav_msgs::msg::CommonGroup";
}

template<>
inline const char * name<vectornav_msgs::msg::CommonGroup>()
{
  return "vectornav_msgs/msg/CommonGroup";
}

template<>
struct has_fixed_size<vectornav_msgs::msg::CommonGroup>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Quaternion>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<vectornav_msgs::msg::InsStatus>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::msg::CommonGroup>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Quaternion>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<vectornav_msgs::msg::InsStatus>::value> {};

template<>
struct is_message<vectornav_msgs::msg::CommonGroup>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VECTORNAV_MSGS__MSG__DETAIL__COMMON_GROUP__TRAITS_HPP_
