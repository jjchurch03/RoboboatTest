// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from main_control:msg/MyCustomMsgMC.idl
// generated code does not contain a copyright notice
#include "main_control/msg/detail/my_custom_msg_mc__rosidl_typesupport_fastrtps_cpp.hpp"
#include "main_control/msg/detail/my_custom_msg_mc__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace main_control
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_main_control
cdr_serialize(
  const main_control::msg::MyCustomMsgMC & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: frame_id
  cdr << ros_message.frame_id;
  // Member: object_classes
  {
    cdr << ros_message.object_classes;
  }
  // Member: object_scores
  {
    cdr << ros_message.object_scores;
  }
  // Member: object_bounding_boxes
  {
    cdr << ros_message.object_bounding_boxes;
  }
  // Member: object_positions
  {
    cdr << ros_message.object_positions;
  }
  // Member: object_orientations
  {
    cdr << ros_message.object_orientations;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_main_control
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  main_control::msg::MyCustomMsgMC & ros_message)
{
  // Member: frame_id
  cdr >> ros_message.frame_id;

  // Member: object_classes
  {
    cdr >> ros_message.object_classes;
  }

  // Member: object_scores
  {
    cdr >> ros_message.object_scores;
  }

  // Member: object_bounding_boxes
  {
    cdr >> ros_message.object_bounding_boxes;
  }

  // Member: object_positions
  {
    cdr >> ros_message.object_positions;
  }

  // Member: object_orientations
  {
    cdr >> ros_message.object_orientations;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_main_control
get_serialized_size(
  const main_control::msg::MyCustomMsgMC & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.frame_id.size() + 1);
  // Member: object_classes
  {
    size_t array_size = ros_message.object_classes.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.object_classes[index].size() + 1);
    }
  }
  // Member: object_scores
  {
    size_t array_size = ros_message.object_scores.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.object_scores[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: object_bounding_boxes
  {
    size_t array_size = ros_message.object_bounding_boxes.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.object_bounding_boxes[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: object_positions
  {
    size_t array_size = ros_message.object_positions.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.object_positions[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: object_orientations
  {
    size_t array_size = ros_message.object_orientations.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.object_orientations[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_main_control
max_serialized_size_MyCustomMsgMC(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: frame_id
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: object_classes
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: object_scores
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: object_bounding_boxes
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: object_positions
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: object_orientations
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _MyCustomMsgMC__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const main_control::msg::MyCustomMsgMC *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MyCustomMsgMC__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<main_control::msg::MyCustomMsgMC *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MyCustomMsgMC__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const main_control::msg::MyCustomMsgMC *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MyCustomMsgMC__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MyCustomMsgMC(full_bounded, 0);
}

static message_type_support_callbacks_t _MyCustomMsgMC__callbacks = {
  "main_control::msg",
  "MyCustomMsgMC",
  _MyCustomMsgMC__cdr_serialize,
  _MyCustomMsgMC__cdr_deserialize,
  _MyCustomMsgMC__get_serialized_size,
  _MyCustomMsgMC__max_serialized_size
};

static rosidl_message_type_support_t _MyCustomMsgMC__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MyCustomMsgMC__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace main_control

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_main_control
const rosidl_message_type_support_t *
get_message_type_support_handle<main_control::msg::MyCustomMsgMC>()
{
  return &main_control::msg::typesupport_fastrtps_cpp::_MyCustomMsgMC__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, main_control, msg, MyCustomMsgMC)() {
  return &main_control::msg::typesupport_fastrtps_cpp::_MyCustomMsgMC__handle;
}

#ifdef __cplusplus
}
#endif
