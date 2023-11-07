// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from main_control:msg/MyCustomMsg.idl
// generated code does not contain a copyright notice

#ifndef MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__FUNCTIONS_H_
#define MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "main_control/msg/rosidl_generator_c__visibility_control.h"

#include "main_control/msg/detail/my_custom_msg__struct.h"

/// Initialize msg/MyCustomMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * main_control__msg__MyCustomMsg
 * )) before or use
 * main_control__msg__MyCustomMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
bool
main_control__msg__MyCustomMsg__init(main_control__msg__MyCustomMsg * msg);

/// Finalize msg/MyCustomMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
void
main_control__msg__MyCustomMsg__fini(main_control__msg__MyCustomMsg * msg);

/// Create msg/MyCustomMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * main_control__msg__MyCustomMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
main_control__msg__MyCustomMsg *
main_control__msg__MyCustomMsg__create();

/// Destroy msg/MyCustomMsg message.
/**
 * It calls
 * main_control__msg__MyCustomMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
void
main_control__msg__MyCustomMsg__destroy(main_control__msg__MyCustomMsg * msg);

/// Check for msg/MyCustomMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
bool
main_control__msg__MyCustomMsg__are_equal(const main_control__msg__MyCustomMsg * lhs, const main_control__msg__MyCustomMsg * rhs);

/// Copy a msg/MyCustomMsg message.
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
ROSIDL_GENERATOR_C_PUBLIC_main_control
bool
main_control__msg__MyCustomMsg__copy(
  const main_control__msg__MyCustomMsg * input,
  main_control__msg__MyCustomMsg * output);

/// Initialize array of msg/MyCustomMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * main_control__msg__MyCustomMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
bool
main_control__msg__MyCustomMsg__Sequence__init(main_control__msg__MyCustomMsg__Sequence * array, size_t size);

/// Finalize array of msg/MyCustomMsg messages.
/**
 * It calls
 * main_control__msg__MyCustomMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
void
main_control__msg__MyCustomMsg__Sequence__fini(main_control__msg__MyCustomMsg__Sequence * array);

/// Create array of msg/MyCustomMsg messages.
/**
 * It allocates the memory for the array and calls
 * main_control__msg__MyCustomMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
main_control__msg__MyCustomMsg__Sequence *
main_control__msg__MyCustomMsg__Sequence__create(size_t size);

/// Destroy array of msg/MyCustomMsg messages.
/**
 * It calls
 * main_control__msg__MyCustomMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
void
main_control__msg__MyCustomMsg__Sequence__destroy(main_control__msg__MyCustomMsg__Sequence * array);

/// Check for msg/MyCustomMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_main_control
bool
main_control__msg__MyCustomMsg__Sequence__are_equal(const main_control__msg__MyCustomMsg__Sequence * lhs, const main_control__msg__MyCustomMsg__Sequence * rhs);

/// Copy an array of msg/MyCustomMsg messages.
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
ROSIDL_GENERATOR_C_PUBLIC_main_control
bool
main_control__msg__MyCustomMsg__Sequence__copy(
  const main_control__msg__MyCustomMsg__Sequence * input,
  main_control__msg__MyCustomMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MAIN_CONTROL__MSG__DETAIL__MY_CUSTOM_MSG__FUNCTIONS_H_
