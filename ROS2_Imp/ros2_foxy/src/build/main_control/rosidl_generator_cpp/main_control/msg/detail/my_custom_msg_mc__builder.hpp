// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from main_control:msg/MyCustomMsgMC.idl
// generated code does not contain a copyright notice

#ifndef MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG_MC__BUILDER_HPP_
#define MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG_MC__BUILDER_HPP_

#include "main_control/msg/detail/my_custom_msg_mc__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace main_control
{

namespace msg
{

namespace builder
{

class Init_MyCustomMsgMC_object_orientations
{
public:
  explicit Init_MyCustomMsgMC_object_orientations(::main_control::msg::MyCustomMsgMC & msg)
  : msg_(msg)
  {}
  ::main_control::msg::MyCustomMsgMC object_orientations(::main_control::msg::MyCustomMsgMC::_object_orientations_type arg)
  {
    msg_.object_orientations = std::move(arg);
    return std::move(msg_);
  }

private:
  ::main_control::msg::MyCustomMsgMC msg_;
};

class Init_MyCustomMsgMC_object_positions
{
public:
  explicit Init_MyCustomMsgMC_object_positions(::main_control::msg::MyCustomMsgMC & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsgMC_object_orientations object_positions(::main_control::msg::MyCustomMsgMC::_object_positions_type arg)
  {
    msg_.object_positions = std::move(arg);
    return Init_MyCustomMsgMC_object_orientations(msg_);
  }

private:
  ::main_control::msg::MyCustomMsgMC msg_;
};

class Init_MyCustomMsgMC_object_bounding_boxes
{
public:
  explicit Init_MyCustomMsgMC_object_bounding_boxes(::main_control::msg::MyCustomMsgMC & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsgMC_object_positions object_bounding_boxes(::main_control::msg::MyCustomMsgMC::_object_bounding_boxes_type arg)
  {
    msg_.object_bounding_boxes = std::move(arg);
    return Init_MyCustomMsgMC_object_positions(msg_);
  }

private:
  ::main_control::msg::MyCustomMsgMC msg_;
};

class Init_MyCustomMsgMC_object_scores
{
public:
  explicit Init_MyCustomMsgMC_object_scores(::main_control::msg::MyCustomMsgMC & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsgMC_object_bounding_boxes object_scores(::main_control::msg::MyCustomMsgMC::_object_scores_type arg)
  {
    msg_.object_scores = std::move(arg);
    return Init_MyCustomMsgMC_object_bounding_boxes(msg_);
  }

private:
  ::main_control::msg::MyCustomMsgMC msg_;
};

class Init_MyCustomMsgMC_object_classes
{
public:
  explicit Init_MyCustomMsgMC_object_classes(::main_control::msg::MyCustomMsgMC & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsgMC_object_scores object_classes(::main_control::msg::MyCustomMsgMC::_object_classes_type arg)
  {
    msg_.object_classes = std::move(arg);
    return Init_MyCustomMsgMC_object_scores(msg_);
  }

private:
  ::main_control::msg::MyCustomMsgMC msg_;
};

class Init_MyCustomMsgMC_frame_id
{
public:
  Init_MyCustomMsgMC_frame_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyCustomMsgMC_object_classes frame_id(::main_control::msg::MyCustomMsgMC::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_MyCustomMsgMC_object_classes(msg_);
  }

private:
  ::main_control::msg::MyCustomMsgMC msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::main_control::msg::MyCustomMsgMC>()
{
  return main_control::msg::builder::Init_MyCustomMsgMC_frame_id();
}

}  // namespace main_control

#endif  // MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG_MC__BUILDER_HPP_
