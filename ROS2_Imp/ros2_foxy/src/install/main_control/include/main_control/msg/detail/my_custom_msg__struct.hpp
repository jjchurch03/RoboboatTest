// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from main_control:msg/MyCustomMsg.idl
// generated code does not contain a copyright notice

#ifndef MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__STRUCT_HPP_
#define MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__main_control__msg__MyCustomMsg __attribute__((deprecated))
#else
# define DEPRECATED__main_control__msg__MyCustomMsg __declspec(deprecated)
#endif

namespace main_control
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MyCustomMsg_
{
  using Type = MyCustomMsg_<ContainerAllocator>;

  explicit MyCustomMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
    }
  }

  explicit MyCustomMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : frame_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
    }
  }

  // field types and members
  using _frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _frame_id_type frame_id;
  using _object_classes_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _object_classes_type object_classes;
  using _object_scores_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _object_scores_type object_scores;
  using _object_bounding_boxes_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _object_bounding_boxes_type object_bounding_boxes;
  using _object_positions_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _object_positions_type object_positions;
  using _object_orientations_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _object_orientations_type object_orientations;

  // setters for named parameter idiom
  Type & set__frame_id(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->frame_id = _arg;
    return *this;
  }
  Type & set__object_classes(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->object_classes = _arg;
    return *this;
  }
  Type & set__object_scores(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->object_scores = _arg;
    return *this;
  }
  Type & set__object_bounding_boxes(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->object_bounding_boxes = _arg;
    return *this;
  }
  Type & set__object_positions(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->object_positions = _arg;
    return *this;
  }
  Type & set__object_orientations(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->object_orientations = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    main_control::msg::MyCustomMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const main_control::msg::MyCustomMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<main_control::msg::MyCustomMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<main_control::msg::MyCustomMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      main_control::msg::MyCustomMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<main_control::msg::MyCustomMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      main_control::msg::MyCustomMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<main_control::msg::MyCustomMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<main_control::msg::MyCustomMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<main_control::msg::MyCustomMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__main_control__msg__MyCustomMsg
    std::shared_ptr<main_control::msg::MyCustomMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__main_control__msg__MyCustomMsg
    std::shared_ptr<main_control::msg::MyCustomMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyCustomMsg_ & other) const
  {
    if (this->frame_id != other.frame_id) {
      return false;
    }
    if (this->object_classes != other.object_classes) {
      return false;
    }
    if (this->object_scores != other.object_scores) {
      return false;
    }
    if (this->object_bounding_boxes != other.object_bounding_boxes) {
      return false;
    }
    if (this->object_positions != other.object_positions) {
      return false;
    }
    if (this->object_orientations != other.object_orientations) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyCustomMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyCustomMsg_

// alias to use template instance with default allocator
using MyCustomMsg =
  main_control::msg::MyCustomMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace main_control

#endif  // MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__STRUCT_HPP_
