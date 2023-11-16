// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from detector:msg/MyCustomMsgDetector.idl
// generated code does not contain a copyright notice

#ifndef DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__BUILDER_HPP_
#define DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__BUILDER_HPP_

#include "detector/msg/detail/my_custom_msg_detector__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace detector
{

namespace msg
{

namespace builder
{

class Init_MyCustomMsgDetector_object_orientations
{
public:
  explicit Init_MyCustomMsgDetector_object_orientations(::detector::msg::MyCustomMsgDetector & msg)
  : msg_(msg)
  {}
  ::detector::msg::MyCustomMsgDetector object_orientations(::detector::msg::MyCustomMsgDetector::_object_orientations_type arg)
  {
    msg_.object_orientations = std::move(arg);
    return std::move(msg_);
  }

private:
  ::detector::msg::MyCustomMsgDetector msg_;
};

class Init_MyCustomMsgDetector_object_positions
{
public:
  explicit Init_MyCustomMsgDetector_object_positions(::detector::msg::MyCustomMsgDetector & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsgDetector_object_orientations object_positions(::detector::msg::MyCustomMsgDetector::_object_positions_type arg)
  {
    msg_.object_positions = std::move(arg);
    return Init_MyCustomMsgDetector_object_orientations(msg_);
  }

private:
  ::detector::msg::MyCustomMsgDetector msg_;
};

class Init_MyCustomMsgDetector_object_bounding_boxes
{
public:
  explicit Init_MyCustomMsgDetector_object_bounding_boxes(::detector::msg::MyCustomMsgDetector & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsgDetector_object_positions object_bounding_boxes(::detector::msg::MyCustomMsgDetector::_object_bounding_boxes_type arg)
  {
    msg_.object_bounding_boxes = std::move(arg);
    return Init_MyCustomMsgDetector_object_positions(msg_);
  }

private:
  ::detector::msg::MyCustomMsgDetector msg_;
};

class Init_MyCustomMsgDetector_object_scores
{
public:
  explicit Init_MyCustomMsgDetector_object_scores(::detector::msg::MyCustomMsgDetector & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsgDetector_object_bounding_boxes object_scores(::detector::msg::MyCustomMsgDetector::_object_scores_type arg)
  {
    msg_.object_scores = std::move(arg);
    return Init_MyCustomMsgDetector_object_bounding_boxes(msg_);
  }

private:
  ::detector::msg::MyCustomMsgDetector msg_;
};

class Init_MyCustomMsgDetector_object_classes
{
public:
  explicit Init_MyCustomMsgDetector_object_classes(::detector::msg::MyCustomMsgDetector & msg)
  : msg_(msg)
  {}
  Init_MyCustomMsgDetector_object_scores object_classes(::detector::msg::MyCustomMsgDetector::_object_classes_type arg)
  {
    msg_.object_classes = std::move(arg);
    return Init_MyCustomMsgDetector_object_scores(msg_);
  }

private:
  ::detector::msg::MyCustomMsgDetector msg_;
};

class Init_MyCustomMsgDetector_frame_id
{
public:
  Init_MyCustomMsgDetector_frame_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyCustomMsgDetector_object_classes frame_id(::detector::msg::MyCustomMsgDetector::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_MyCustomMsgDetector_object_classes(msg_);
  }

private:
  ::detector::msg::MyCustomMsgDetector msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::detector::msg::MyCustomMsgDetector>()
{
  return detector::msg::builder::Init_MyCustomMsgDetector_frame_id();
}

}  // namespace detector

#endif  // DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__BUILDER_HPP_
