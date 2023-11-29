// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vectornav_msgs:msg/AttitudeGroup.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vectornav_msgs/msg/detail/attitude_group__rosidl_typesupport_introspection_c.h"
#include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vectornav_msgs/msg/detail/attitude_group__functions.h"
#include "vectornav_msgs/msg/detail/attitude_group__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `vpestatus`
#include "vectornav_msgs/msg/vpe_status.h"
// Member `vpestatus`
#include "vectornav_msgs/msg/detail/vpe_status__rosidl_typesupport_introspection_c.h"
// Member `yawpitchroll`
// Member `magned`
// Member `accelned`
// Member `linearaccelbody`
// Member `linearaccelned`
// Member `ypru`
#include "geometry_msgs/msg/vector3.h"
// Member `yawpitchroll`
// Member `magned`
// Member `accelned`
// Member `linearaccelbody`
// Member `linearaccelned`
// Member `ypru`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `quaternion`
#include "geometry_msgs/msg/quaternion.h"
// Member `quaternion`
#include "geometry_msgs/msg/detail/quaternion__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vectornav_msgs__msg__AttitudeGroup__init(message_memory);
}

void AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_fini_function(void * message_memory)
{
  vectornav_msgs__msg__AttitudeGroup__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[11] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "group_fields",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, group_fields),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vpestatus",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, vpestatus),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yawpitchroll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, yawpitchroll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "quaternion",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, quaternion),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dcm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    9,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, dcm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "magned",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, magned),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "accelned",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, accelned),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linearaccelbody",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, linearaccelbody),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linearaccelned",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, linearaccelned),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ypru",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__msg__AttitudeGroup, ypru),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_members = {
  "vectornav_msgs__msg",  // message namespace
  "AttitudeGroup",  // message name
  11,  // number of fields
  sizeof(vectornav_msgs__msg__AttitudeGroup),
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array,  // message members
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_init_function,  // function to initialize message memory (memory has to be allocated)
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_type_support_handle = {
  0,
  &AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, msg, AttitudeGroup)() {
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, msg, VpeStatus)();
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Quaternion)();
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[9].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_member_array[10].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_type_support_handle.typesupport_identifier) {
    AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &AttitudeGroup__rosidl_typesupport_introspection_c__AttitudeGroup_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
