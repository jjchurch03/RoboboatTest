// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from main_control:msg/MyCustomMsgMC.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "main_control/msg/detail/my_custom_msg_mc__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace main_control
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MyCustomMsgMC_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) main_control::msg::MyCustomMsgMC(_init);
}

void MyCustomMsgMC_fini_function(void * message_memory)
{
  auto typed_message = static_cast<main_control::msg::MyCustomMsgMC *>(message_memory);
  typed_message->~MyCustomMsgMC();
}

size_t size_function__MyCustomMsgMC__object_classes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MyCustomMsgMC__object_classes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__MyCustomMsgMC__object_classes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void resize_function__MyCustomMsgMC__object_classes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MyCustomMsgMC__object_scores(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MyCustomMsgMC__object_scores(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MyCustomMsgMC__object_scores(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void resize_function__MyCustomMsgMC__object_scores(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MyCustomMsgMC__object_bounding_boxes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MyCustomMsgMC__object_bounding_boxes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MyCustomMsgMC__object_bounding_boxes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void resize_function__MyCustomMsgMC__object_bounding_boxes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MyCustomMsgMC__object_positions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MyCustomMsgMC__object_positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MyCustomMsgMC__object_positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void resize_function__MyCustomMsgMC__object_positions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MyCustomMsgMC__object_orientations(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MyCustomMsgMC__object_orientations(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MyCustomMsgMC__object_orientations(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void resize_function__MyCustomMsgMC__object_orientations(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MyCustomMsgMC_message_member_array[6] = {
  {
    "frame_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(main_control::msg::MyCustomMsgMC, frame_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "object_classes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(main_control::msg::MyCustomMsgMC, object_classes),  // bytes offset in struct
    nullptr,  // default value
    size_function__MyCustomMsgMC__object_classes,  // size() function pointer
    get_const_function__MyCustomMsgMC__object_classes,  // get_const(index) function pointer
    get_function__MyCustomMsgMC__object_classes,  // get(index) function pointer
    resize_function__MyCustomMsgMC__object_classes  // resize(index) function pointer
  },
  {
    "object_scores",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(main_control::msg::MyCustomMsgMC, object_scores),  // bytes offset in struct
    nullptr,  // default value
    size_function__MyCustomMsgMC__object_scores,  // size() function pointer
    get_const_function__MyCustomMsgMC__object_scores,  // get_const(index) function pointer
    get_function__MyCustomMsgMC__object_scores,  // get(index) function pointer
    resize_function__MyCustomMsgMC__object_scores  // resize(index) function pointer
  },
  {
    "object_bounding_boxes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(main_control::msg::MyCustomMsgMC, object_bounding_boxes),  // bytes offset in struct
    nullptr,  // default value
    size_function__MyCustomMsgMC__object_bounding_boxes,  // size() function pointer
    get_const_function__MyCustomMsgMC__object_bounding_boxes,  // get_const(index) function pointer
    get_function__MyCustomMsgMC__object_bounding_boxes,  // get(index) function pointer
    resize_function__MyCustomMsgMC__object_bounding_boxes  // resize(index) function pointer
  },
  {
    "object_positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(main_control::msg::MyCustomMsgMC, object_positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__MyCustomMsgMC__object_positions,  // size() function pointer
    get_const_function__MyCustomMsgMC__object_positions,  // get_const(index) function pointer
    get_function__MyCustomMsgMC__object_positions,  // get(index) function pointer
    resize_function__MyCustomMsgMC__object_positions  // resize(index) function pointer
  },
  {
    "object_orientations",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(main_control::msg::MyCustomMsgMC, object_orientations),  // bytes offset in struct
    nullptr,  // default value
    size_function__MyCustomMsgMC__object_orientations,  // size() function pointer
    get_const_function__MyCustomMsgMC__object_orientations,  // get_const(index) function pointer
    get_function__MyCustomMsgMC__object_orientations,  // get(index) function pointer
    resize_function__MyCustomMsgMC__object_orientations  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MyCustomMsgMC_message_members = {
  "main_control::msg",  // message namespace
  "MyCustomMsgMC",  // message name
  6,  // number of fields
  sizeof(main_control::msg::MyCustomMsgMC),
  MyCustomMsgMC_message_member_array,  // message members
  MyCustomMsgMC_init_function,  // function to initialize message memory (memory has to be allocated)
  MyCustomMsgMC_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MyCustomMsgMC_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MyCustomMsgMC_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace main_control


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<main_control::msg::MyCustomMsgMC>()
{
  return &::main_control::msg::rosidl_typesupport_introspection_cpp::MyCustomMsgMC_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, main_control, msg, MyCustomMsgMC)() {
  return &::main_control::msg::rosidl_typesupport_introspection_cpp::MyCustomMsgMC_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
