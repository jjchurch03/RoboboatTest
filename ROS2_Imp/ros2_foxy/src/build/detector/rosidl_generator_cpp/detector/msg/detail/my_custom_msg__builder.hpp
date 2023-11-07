// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from detector:msg/MyCustomMsg.idl
// generated code does not contain a copyright notice

#ifndef DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG__BUILDER_HPP_
#define DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG__BUILDER_HPP_

#include "detector/msg/detail/my_custom_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace detector
{

namespace msg
{

namespace builder
{

class Init_MyCustomMsg_object_orientations
{
public:
  explicit Init_MyCustomMsg_object_orientations(::detector::msg::MyCustomMsg & msg)
  : msg_(msg)
  {}
  ::detector::msg::MyCustomMsg object_orientations(::detector::msg::MyCustomMsg::_object_orientations_type arg)
  {
    msg_.object_orientations = std::move(arg);
    return std::move(msg_);
  }

private:
  ::detector::msg::MyCustomMsg msg_;
};

class Init_MyCustomMsg_object_positions
{
public:
  explicit Init_MyCustomMsg_object_positions(::detector::msg::MyCustomMsg & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsg_object_orientations object_positions(::detector::msg::MyCustomMsg::_object_positions_type arg)
  {
    msg_.object_positions = std::move(arg);
    return Init_MyCustomMsg_object_orientations(msg_);
  }

private:
  ::detector::msg::MyCustomMsg msg_;
};

class Init_MyCustomMsg_object_bounding_boxes
{
public:
  explicit Init_MyCustomMsg_object_bounding_boxes(::detector::msg::MyCustomMsg & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsg_object_positions object_bounding_boxes(::detector::msg::MyCustomMsg::_object_bounding_boxes_type arg)
  {
    msg_.object_bounding_boxes = std::move(arg);
    return Init_MyCustomMsg_object_positions(msg_);
  }

private:
  ::detector::msg::MyCustomMsg msg_;
};

class Init_MyCustomMsg_object_scores
{
public:
  explicit Init_MyCustomMsg_object_scores(::detector::msg::MyCustomMsg & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsg_object_bounding_boxes object_scores(::detector::msg::MyCustomMsg::_object_scores_type arg)
  {
    msg_.object_scores = std::move(arg);
    return Init_MyCustomMsg_object_bounding_boxes(msg_);
  }

private:
  ::detector::msg::MyCustomMsg msg_;
};

class Init_MyCustomMsg_object_classes
{
public:
  explicit Init_MyCustomMsg_object_classes(::detector::msg::MyCustomMsg & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsg_object_scores object_classes(::detector::msg::MyCustomMsg::_object_classes_type arg)
  {
    msg_.object_classes = std::move(arg);
    return Init_MyCustomMsg_object_scores(msg_);
  }

private:
  ::detector::msg::MyCustomMsg msg_;
};

class Init_MyCustomMsg_frame_id
{
public:
  Init_MyCustomMsg_frame_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyCustomMsg_object_classes frame_id(::detector::msg::MyCustomMsg::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_MyCustomMsg_object_classes(msg_);
  }

private:
  ::detector::msg::MyCustomMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::detector::msg::MyCustomMsg>()
{
  return detector::msg::builder::Init_MyCustomMsg_frame_id();
}

}  // namespace detector

#endif  // DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG__BUILDER_HPP_
