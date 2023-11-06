// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from detector:msg/YOLOv5helper.idl
// generated code does not contain a copyright notice

#ifndef DETECTOR__MSG__DETAIL__YOL_OV5HELPER__BUILDER_HPP_
#define DETECTOR__MSG__DETAIL__YOL_OV5HELPER__BUILDER_HPP_

#include "detector/msg/detail/yol_ov5helper__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace detector
{

namespace msg
{

namespace builder
{

class Init_YOLOv5helper_object_orientations
{
public:
  explicit Init_YOLOv5helper_object_orientations(::detector::msg::YOLOv5helper & msg)
  : msg_(msg)
  {}
  ::detector::msg::YOLOv5helper object_orientations(::detector::msg::YOLOv5helper::_object_orientations_type arg)
  {
    msg_.object_orientations = std::move(arg);
    return std::move(msg_);
  }

private:
  ::detector::msg::YOLOv5helper msg_;
};

class Init_YOLOv5helper_object_positions
{
public:
  explicit Init_YOLOv5helper_object_positions(::detector::msg::YOLOv5helper & msg)
  : msg_(msg)
  {}
  Init_YOLOv5helper_object_orientations object_positions(::detector::msg::YOLOv5helper::_object_positions_type arg)
  {
    msg_.object_positions = std::move(arg);
    return Init_YOLOv5helper_object_orientations(msg_);
  }

private:
  ::detector::msg::YOLOv5helper msg_;
};

class Init_YOLOv5helper_object_bounding_boxes
{
public:
  explicit Init_YOLOv5helper_object_bounding_boxes(::detector::msg::YOLOv5helper & msg)
  : msg_(msg)
  {}
  Init_YOLOv5helper_object_positions object_bounding_boxes(::detector::msg::YOLOv5helper::_object_bounding_boxes_type arg)
  {
    msg_.object_bounding_boxes = std::move(arg);
    return Init_YOLOv5helper_object_positions(msg_);
  }

private:
  ::detector::msg::YOLOv5helper msg_;
};

class Init_YOLOv5helper_object_scores
{
public:
  explicit Init_YOLOv5helper_object_scores(::detector::msg::YOLOv5helper & msg)
  : msg_(msg)
  {}
  Init_YOLOv5helper_object_bounding_boxes object_scores(::detector::msg::YOLOv5helper::_object_scores_type arg)
  {
    msg_.object_scores = std::move(arg);
    return Init_YOLOv5helper_object_bounding_boxes(msg_);
  }

private:
  ::detector::msg::YOLOv5helper msg_;
};

class Init_YOLOv5helper_object_classes
{
public:
  explicit Init_YOLOv5helper_object_classes(::detector::msg::YOLOv5helper & msg)
  : msg_(msg)
  {}
  Init_YOLOv5helper_object_scores object_classes(::detector::msg::YOLOv5helper::_object_classes_type arg)
  {
    msg_.object_classes = std::move(arg);
    return Init_YOLOv5helper_object_scores(msg_);
  }

private:
  ::detector::msg::YOLOv5helper msg_;
};

class Init_YOLOv5helper_frame_id
{
public:
  Init_YOLOv5helper_frame_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YOLOv5helper_object_classes frame_id(::detector::msg::YOLOv5helper::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_YOLOv5helper_object_classes(msg_);
  }

private:
  ::detector::msg::YOLOv5helper msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::detector::msg::YOLOv5helper>()
{
  return detector::msg::builder::Init_YOLOv5helper_frame_id();
}

}  // namespace detector

#endif  // DETECTOR__MSG__DETAIL__YOL_OV5HELPER__BUILDER_HPP_
