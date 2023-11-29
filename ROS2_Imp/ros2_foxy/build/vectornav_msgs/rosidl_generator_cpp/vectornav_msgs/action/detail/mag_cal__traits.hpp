// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vectornav_msgs:action/MagCal.idl
// generated code does not contain a copyright notice

#ifndef VECTORNAV_MSGS__ACTION__DETAIL__MAG_CAL__TRAITS_HPP_
#define VECTORNAV_MSGS__ACTION__DETAIL__MAG_CAL__TRAITS_HPP_

#include "vectornav_msgs/action/detail/mag_cal__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_Goal>()
{
  return "vectornav_msgs::action::MagCal_Goal";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_Goal>()
{
  return "vectornav_msgs/action/MagCal_Goal";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vectornav_msgs::action::MagCal_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_Result>()
{
  return "vectornav_msgs::action::MagCal_Result";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_Result>()
{
  return "vectornav_msgs/action/MagCal_Result";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vectornav_msgs::action::MagCal_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_Feedback>()
{
  return "vectornav_msgs::action::MagCal_Feedback";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_Feedback>()
{
  return "vectornav_msgs/action/MagCal_Feedback";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vectornav_msgs::action::MagCal_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "vectornav_msgs/action/detail/mag_cal__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_SendGoal_Request>()
{
  return "vectornav_msgs::action::MagCal_SendGoal_Request";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_SendGoal_Request>()
{
  return "vectornav_msgs/action/MagCal_SendGoal_Request";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value && has_fixed_size<vectornav_msgs::action::MagCal_Goal>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value && has_bounded_size<vectornav_msgs::action::MagCal_Goal>::value> {};

template<>
struct is_message<vectornav_msgs::action::MagCal_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_SendGoal_Response>()
{
  return "vectornav_msgs::action::MagCal_SendGoal_Response";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_SendGoal_Response>()
{
  return "vectornav_msgs/action/MagCal_SendGoal_Response";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<vectornav_msgs::action::MagCal_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_SendGoal>()
{
  return "vectornav_msgs::action::MagCal_SendGoal";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_SendGoal>()
{
  return "vectornav_msgs/action/MagCal_SendGoal";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<vectornav_msgs::action::MagCal_SendGoal_Request>::value &&
    has_fixed_size<vectornav_msgs::action::MagCal_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<vectornav_msgs::action::MagCal_SendGoal_Request>::value &&
    has_bounded_size<vectornav_msgs::action::MagCal_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<vectornav_msgs::action::MagCal_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<vectornav_msgs::action::MagCal_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vectornav_msgs::action::MagCal_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_GetResult_Request>()
{
  return "vectornav_msgs::action::MagCal_GetResult_Request";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_GetResult_Request>()
{
  return "vectornav_msgs/action/MagCal_GetResult_Request";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<vectornav_msgs::action::MagCal_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_GetResult_Response>()
{
  return "vectornav_msgs::action::MagCal_GetResult_Response";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_GetResult_Response>()
{
  return "vectornav_msgs/action/MagCal_GetResult_Response";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<vectornav_msgs::action::MagCal_Result>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<vectornav_msgs::action::MagCal_Result>::value> {};

template<>
struct is_message<vectornav_msgs::action::MagCal_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_GetResult>()
{
  return "vectornav_msgs::action::MagCal_GetResult";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_GetResult>()
{
  return "vectornav_msgs/action/MagCal_GetResult";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<vectornav_msgs::action::MagCal_GetResult_Request>::value &&
    has_fixed_size<vectornav_msgs::action::MagCal_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<vectornav_msgs::action::MagCal_GetResult_Request>::value &&
    has_bounded_size<vectornav_msgs::action::MagCal_GetResult_Response>::value
  >
{
};

template<>
struct is_service<vectornav_msgs::action::MagCal_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<vectornav_msgs::action::MagCal_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vectornav_msgs::action::MagCal_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vectornav_msgs::action::MagCal_FeedbackMessage>()
{
  return "vectornav_msgs::action::MagCal_FeedbackMessage";
}

template<>
inline const char * name<vectornav_msgs::action::MagCal_FeedbackMessage>()
{
  return "vectornav_msgs/action/MagCal_FeedbackMessage";
}

template<>
struct has_fixed_size<vectornav_msgs::action::MagCal_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value && has_fixed_size<vectornav_msgs::action::MagCal_Feedback>::value> {};

template<>
struct has_bounded_size<vectornav_msgs::action::MagCal_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value && has_bounded_size<vectornav_msgs::action::MagCal_Feedback>::value> {};

template<>
struct is_message<vectornav_msgs::action::MagCal_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<vectornav_msgs::action::MagCal>
  : std::true_type
{
};

template<>
struct is_action_goal<vectornav_msgs::action::MagCal_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<vectornav_msgs::action::MagCal_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<vectornav_msgs::action::MagCal_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // VECTORNAV_MSGS__ACTION__DETAIL__MAG_CAL__TRAITS_HPP_
