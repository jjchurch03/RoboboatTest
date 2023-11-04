// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from detector:msg/YOLOv5helper.idl
// generated code does not contain a copyright notice

#ifndef DETECTOR__MSG__DETAIL__YOL_OV5HELPER__TRAITS_HPP_
#define DETECTOR__MSG__DETAIL__YOL_OV5HELPER__TRAITS_HPP_

#include "detector/msg/detail/yol_ov5helper__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<detector::msg::YOLOv5helper>()
{
  return "detector::msg::YOLOv5helper";
}

template<>
inline const char * name<detector::msg::YOLOv5helper>()
{
  return "detector/msg/YOLOv5helper";
}

template<>
struct has_fixed_size<detector::msg::YOLOv5helper>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<detector::msg::YOLOv5helper>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<detector::msg::YOLOv5helper>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DETECTOR__MSG__DETAIL__YOL_OV5HELPER__TRAITS_HPP_
