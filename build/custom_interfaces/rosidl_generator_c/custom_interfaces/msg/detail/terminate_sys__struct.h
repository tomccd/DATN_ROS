// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/TerminateSys.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/terminate_sys.h"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE_SYS__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE_SYS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'a'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TerminateSys in the package custom_interfaces.
typedef struct custom_interfaces__msg__TerminateSys
{
  rosidl_runtime_c__String a;
} custom_interfaces__msg__TerminateSys;

// Struct for a sequence of custom_interfaces__msg__TerminateSys.
typedef struct custom_interfaces__msg__TerminateSys__Sequence
{
  custom_interfaces__msg__TerminateSys * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__TerminateSys__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE_SYS__STRUCT_H_
