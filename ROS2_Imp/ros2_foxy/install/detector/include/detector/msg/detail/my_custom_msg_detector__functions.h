// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from detector:msg/MyCustomMsgDetector.idl
// generated code does not contain a copyright notice

#ifndef DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__FUNCTIONS_H_
#define DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "detector/msg/rosidl_generator_c__visibility_control.h"

#include "detector/msg/detail/my_custom_msg_detector__struct.h"

/// Initialize msg/MyCustomMsgDetector message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * detector__msg__MyCustomMsgDetector
 * )) before or use
 * detector__msg__MyCustomMsgDetector__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
bool
detector__msg__MyCustomMsgDetector__init(detector__msg__MyCustomMsgDetector * msg);

/// Finalize msg/MyCustomMsgDetector message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
void
detector__msg__MyCustomMsgDetector__fini(detector__msg__MyCustomMsgDetector * msg);

/// Create msg/MyCustomMsgDetector message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * detector__msg__MyCustomMsgDetector__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
detector__msg__MyCustomMsgDetector *
detector__msg__MyCustomMsgDetector__create();

/// Destroy msg/MyCustomMsgDetector message.
/**
 * It calls
 * detector__msg__MyCustomMsgDetector__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
void
detector__msg__MyCustomMsgDetector__destroy(detector__msg__MyCustomMsgDetector * msg);

/// Check for msg/MyCustomMsgDetector message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
bool
detector__msg__MyCustomMsgDetector__are_equal(const detector__msg__MyCustomMsgDetector * lhs, const detector__msg__MyCustomMsgDetector * rhs);

/// Copy a msg/MyCustomMsgDetector message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
bool
detector__msg__MyCustomMsgDetector__copy(
  const detector__msg__MyCustomMsgDetector * input,
  detector__msg__MyCustomMsgDetector * output);

/// Initialize array of msg/MyCustomMsgDetector messages.
/**
 * It allocates the memory for the number of elements and calls
 * detector__msg__MyCustomMsgDetector__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
bool
detector__msg__MyCustomMsgDetector__Sequence__init(detector__msg__MyCustomMsgDetector__Sequence * array, size_t size);

/// Finalize array of msg/MyCustomMsgDetector messages.
/**
 * It calls
 * detector__msg__MyCustomMsgDetector__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
void
detector__msg__MyCustomMsgDetector__Sequence__fini(detector__msg__MyCustomMsgDetector__Sequence * array);

/// Create array of msg/MyCustomMsgDetector messages.
/**
 * It allocates the memory for the array and calls
 * detector__msg__MyCustomMsgDetector__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
detector__msg__MyCustomMsgDetector__Sequence *
detector__msg__MyCustomMsgDetector__Sequence__create(size_t size);

/// Destroy array of msg/MyCustomMsgDetector messages.
/**
 * It calls
 * detector__msg__MyCustomMsgDetector__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
void
detector__msg__MyCustomMsgDetector__Sequence__destroy(detector__msg__MyCustomMsgDetector__Sequence * array);

/// Check for msg/MyCustomMsgDetector message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
bool
detector__msg__MyCustomMsgDetector__Sequence__are_equal(const detector__msg__MyCustomMsgDetector__Sequence * lhs, const detector__msg__MyCustomMsgDetector__Sequence * rhs);

/// Copy an array of msg/MyCustomMsgDetector messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_detector
bool
detector__msg__MyCustomMsgDetector__Sequence__copy(
  const detector__msg__MyCustomMsgDetector__Sequence * input,
  detector__msg__MyCustomMsgDetector__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DETECTOR__MSG__DETAIL__MY_CUSTOM_MSG_DETECTOR__FUNCTIONS_H_
