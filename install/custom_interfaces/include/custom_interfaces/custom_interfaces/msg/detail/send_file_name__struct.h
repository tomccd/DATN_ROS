// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/SendFileName.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/send_file_name.h"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'fname'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SendFileName in the package custom_interfaces.
typedef struct custom_interfaces__msg__SendFileName
{
  rosidl_runtime_c__String fname;
} custom_interfaces__msg__SendFileName;

// Struct for a sequence of custom_interfaces__msg__SendFileName.
typedef struct custom_interfaces__msg__SendFileName__Sequence
{
  custom_interfaces__msg__SendFileName * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__SendFileName__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__STRUCT_H_
