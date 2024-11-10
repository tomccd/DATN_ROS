# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_module_log_file_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED module_log_file_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(module_log_file_FOUND FALSE)
  elseif(NOT module_log_file_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(module_log_file_FOUND FALSE)
  endif()
  return()
endif()
set(_module_log_file_CONFIG_INCLUDED TRUE)

# output package information
if(NOT module_log_file_FIND_QUIETLY)
  message(STATUS "Found module_log_file: 0.0.0 (${module_log_file_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'module_log_file' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT module_log_file_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(module_log_file_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${module_log_file_DIR}/${_extra}")
endforeach()
