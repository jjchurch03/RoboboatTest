# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_HyperNav_Comms_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED HyperNav_Comms_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(HyperNav_Comms_FOUND FALSE)
  elseif(NOT HyperNav_Comms_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(HyperNav_Comms_FOUND FALSE)
  endif()
  return()
endif()
set(_HyperNav_Comms_CONFIG_INCLUDED TRUE)

# output package information
if(NOT HyperNav_Comms_FIND_QUIETLY)
  message(STATUS "Found HyperNav_Comms: 0.0.0 (${HyperNav_Comms_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'HyperNav_Comms' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${HyperNav_Comms_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(HyperNav_Comms_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${HyperNav_Comms_DIR}/${_extra}")
endforeach()
