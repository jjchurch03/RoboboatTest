// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vectornav_msgs:msg/AttitudeGroup.idl
// generated code does not contain a copyright notice

#ifndef VECTORNAV_MSGS__MSG__DETAIL__ATTITUDE_GROUP__TRAITS_HPP_
#define VECTORNAV_MSGS__MSG__DETAIL__ATTITUDE_GROUP__TRAITS_HPP_

#include "vectornav_msgs/msg/detail/attitude_group__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'vpestatus'
#include "vectornav_msgs/msg/detail/vpe_status__traits.hpp"
// Member 'yawpitchroll'
// Member 'magned'
// Member 'accelned'
// Member 'linearaccelbody'
// Member 'linearaccelned'
// Member 'ypru'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::msg::AttitudeGroup>()
{
  return "vectornav_msgs::msg::AttitudeGroup";
}

template<>
inline const char * name<vectornav_msgs::msg::AttitudeGroup>()
{
  return "vectornav_msgs/msg/AttitudeGroup";
}

template<>
struct has_fixed_size<vectornav_msgs::msg::AttitudeGroup>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Quaternion>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<vectornav_msgs::msg::VpeStatus>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::msg::AttitudeGroup>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Quaternion>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<vectornav_msgs::msg::VpeStatus>::value> {};

template<>
struct is_message<vectornav_msgs::msg::AttitudeGroup>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VECTORNAV_MSGS__MSG__DETAIL__ATTITUDE_GROUP__TRAITS_HPP_
