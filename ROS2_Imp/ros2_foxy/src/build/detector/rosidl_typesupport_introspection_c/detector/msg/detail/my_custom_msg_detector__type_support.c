// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from detector:msg/MyCustomMsgDetector.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "detector/msg/detail/my_custom_msg_detector__rosidl_typesupport_introspection_c.h"
#include "detector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "detector/msg/detail/my_custom_msg_detector__functions.h"
#include "detector/msg/detail/my_custom_msg_detector__struct.h"


// Include directives for member types
// Member `frame_id`
// Member `object_classes`
#include "rosidl_runtime_c/string_functions.h"
// Member `object_scores`
// Member `object_bounding_boxes`
// Member `object_positions`
// Member `object_orientations`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  detector__msg__MyCustomMsgDetector__init(message_memory);
}

void MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_fini_function(void * message_memory)
{
  detector__msg__MyCustomMsgDetector__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_message_member_array[6] = {
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detector__msg__MyCustomMsgDetector, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_classes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detector__msg__MyCustomMsgDetector, object_classes),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_scores",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detector__msg__MyCustomMsgDetector, object_scores),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_bounding_boxes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detector__msg__MyCustomMsgDetector, object_bounding_boxes),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detector__msg__MyCustomMsgDetector, object_positions),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_orientations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(detector__msg__MyCustomMsgDetector, object_orientations),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_message_members = {
  "detector__msg",  // message namespace
  "MyCustomMsgDetector",  // message name
  6,  // number of fields
  sizeof(detector__msg__MyCustomMsgDetector),
  MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_message_member_array,  // message members
  MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_init_function,  // function to initialize message memory (memory has to be allocated)
  MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_message_type_support_handle = {
  0,
  &MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_detector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, detector, msg, MyCustomMsgDetector)() {
  if (!MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_message_type_support_handle.typesupport_identifier) {
    MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MyCustomMsgDetector__rosidl_typesupport_introspection_c__MyCustomMsgDetector_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
