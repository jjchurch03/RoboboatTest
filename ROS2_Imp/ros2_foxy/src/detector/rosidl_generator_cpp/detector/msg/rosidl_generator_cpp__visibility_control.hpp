// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef DETECTOR__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define DETECTOR__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_detector __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_detector __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_detector __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_detector __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_detector
    #define ROSIDL_GENERATOR_CPP_PUBLIC_detector ROSIDL_GENERATOR_CPP_EXPORT_detector
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_detector ROSIDL_GENERATOR_CPP_IMPORT_detector
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_detector __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_detector
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_detector __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_detector
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // DETECTOR__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
