// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vectornav_msgs:action/MagCal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
#include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vectornav_msgs/action/detail/mag_cal__functions.h"
#include "vectornav_msgs/action/detail/mag_cal__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vectornav_msgs__action__MagCal_Goal__init(message_memory);
}

void MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_fini_function(void * message_memory)
{
  vectornav_msgs__action__MagCal_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_Goal, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_message_members = {
  "vectornav_msgs__action",  // message namespace
  "MagCal_Goal",  // message name
  1,  // number of fields
  sizeof(vectornav_msgs__action__MagCal_Goal),
  MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_message_member_array,  // message members
  MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_message_type_support_handle = {
  0,
  &MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_Goal)() {
  if (!MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_message_type_support_handle.typesupport_identifier) {
    MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MagCal_Goal__rosidl_typesupport_introspection_c__MagCal_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vectornav_msgs__action__MagCal_Result__init(message_memory);
}

void MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_fini_function(void * message_memory)
{
  vectornav_msgs__action__MagCal_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_message_member_array[2] = {
  {
    "avg_dev",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_Result, avg_dev),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "calib",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_Result, calib),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_message_members = {
  "vectornav_msgs__action",  // message namespace
  "MagCal_Result",  // message name
  2,  // number of fields
  sizeof(vectornav_msgs__action__MagCal_Result),
  MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_message_member_array,  // message members
  MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_message_type_support_handle = {
  0,
  &MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_Result)() {
  if (!MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_message_type_support_handle.typesupport_identifier) {
    MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MagCal_Result__rosidl_typesupport_introspection_c__MagCal_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vectornav_msgs__action__MagCal_Feedback__init(message_memory);
}

void MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_fini_function(void * message_memory)
{
  vectornav_msgs__action__MagCal_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_message_member_array[3] = {
  {
    "curr_avg_dev",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_Feedback, curr_avg_dev),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "curr_calib",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_Feedback, curr_calib),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "samples",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_Feedback, samples),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_message_members = {
  "vectornav_msgs__action",  // message namespace
  "MagCal_Feedback",  // message name
  3,  // number of fields
  sizeof(vectornav_msgs__action__MagCal_Feedback),
  MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_message_member_array,  // message members
  MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_message_type_support_handle = {
  0,
  &MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_Feedback)() {
  if (!MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_message_type_support_handle.typesupport_identifier) {
    MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MagCal_Feedback__rosidl_typesupport_introspection_c__MagCal_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "vectornav_msgs/action/mag_cal.h"
// Member `goal`
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vectornav_msgs__action__MagCal_SendGoal_Request__init(message_memory);
}

void MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_fini_function(void * message_memory)
{
  vectornav_msgs__action__MagCal_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_members = {
  "vectornav_msgs__action",  // message namespace
  "MagCal_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(vectornav_msgs__action__MagCal_SendGoal_Request),
  MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_member_array,  // message members
  MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_type_support_handle = {
  0,
  &MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_SendGoal_Request)() {
  MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_Goal)();
  if (!MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MagCal_SendGoal_Request__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vectornav_msgs__action__MagCal_SendGoal_Response__init(message_memory);
}

void MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_fini_function(void * message_memory)
{
  vectornav_msgs__action__MagCal_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_members = {
  "vectornav_msgs__action",  // message namespace
  "MagCal_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(vectornav_msgs__action__MagCal_SendGoal_Response),
  MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_member_array,  // message members
  MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_type_support_handle = {
  0,
  &MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_SendGoal_Response)() {
  MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MagCal_SendGoal_Response__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_SendGoal_service_members = {
  "vectornav_msgs__action",  // service namespace
  "MagCal_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_SendGoal_service_type_support_handle = {
  0,
  &vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_SendGoal)() {
  if (!vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_SendGoal_service_type_support_handle.typesupport_identifier) {
    vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_SendGoal_Response)()->data;
  }

  return &vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vectornav_msgs__action__MagCal_GetResult_Request__init(message_memory);
}

void MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_fini_function(void * message_memory)
{
  vectornav_msgs__action__MagCal_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_members = {
  "vectornav_msgs__action",  // message namespace
  "MagCal_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(vectornav_msgs__action__MagCal_GetResult_Request),
  MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_member_array,  // message members
  MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_type_support_handle = {
  0,
  &MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_GetResult_Request)() {
  MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MagCal_GetResult_Request__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "vectornav_msgs/action/mag_cal.h"
// Member `result`
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vectornav_msgs__action__MagCal_GetResult_Response__init(message_memory);
}

void MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_fini_function(void * message_memory)
{
  vectornav_msgs__action__MagCal_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_members = {
  "vectornav_msgs__action",  // message namespace
  "MagCal_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(vectornav_msgs__action__MagCal_GetResult_Response),
  MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_member_array,  // message members
  MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_type_support_handle = {
  0,
  &MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_GetResult_Response)() {
  MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_Result)();
  if (!MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MagCal_GetResult_Response__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_GetResult_service_members = {
  "vectornav_msgs__action",  // service namespace
  "MagCal_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_GetResult_service_type_support_handle = {
  0,
  &vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_GetResult)() {
  if (!vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_GetResult_service_type_support_handle.typesupport_identifier) {
    vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_GetResult_Response)()->data;
  }

  return &vectornav_msgs__action__detail__mag_cal__rosidl_typesupport_introspection_c__MagCal_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vectornav_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__functions.h"
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "vectornav_msgs/action/mag_cal.h"
// Member `feedback`
// already included above
// #include "vectornav_msgs/action/detail/mag_cal__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vectornav_msgs__action__MagCal_FeedbackMessage__init(message_memory);
}

void MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_fini_function(void * message_memory)
{
  vectornav_msgs__action__MagCal_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vectornav_msgs__action__MagCal_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_members = {
  "vectornav_msgs__action",  // message namespace
  "MagCal_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(vectornav_msgs__action__MagCal_FeedbackMessage),
  MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_member_array,  // message members
  MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_type_support_handle = {
  0,
  &MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vectornav_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_FeedbackMessage)() {
  MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vectornav_msgs, action, MagCal_Feedback)();
  if (!MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MagCal_FeedbackMessage__rosidl_typesupport_introspection_c__MagCal_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
