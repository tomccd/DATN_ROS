// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/SetStartStopPending.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/set_start_stop_pending.h"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_START_STOP_PENDING__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_START_STOP_PENDING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SetStartStopPending in the package custom_interfaces.
typedef struct custom_interfaces__msg__SetStartStopPending
{
  rosidl_runtime_c__String command;
} custom_interfaces__msg__SetStartStopPending;

// Struct for a sequence of custom_interfaces__msg__SetStartStopPending.
typedef struct custom_interfaces__msg__SetStartStopPending__Sequence
{
  custom_interfaces__msg__SetStartStopPending * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__SetStartStopPending__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_START_STOP_PENDING__STRUCT_H_
