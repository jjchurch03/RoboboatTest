// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
// generated code does not contain a copyright notice

#ifndef ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__TRAITS_HPP_
#define ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__TRAITS_HPP_

#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>()
{
  return "zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped";
}

template<>
inline const char * name<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>()
{
  return "zed_topic_benchmark_interfaces/msg/BenchmarkStatsStamped";
}

template<>
struct has_fixed_size<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__TRAITS_HPP_
