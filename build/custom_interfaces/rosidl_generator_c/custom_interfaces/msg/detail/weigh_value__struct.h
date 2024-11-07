// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/WeighValue.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/weigh_value.h"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__WEIGH_VALUE__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__WEIGH_VALUE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/WeighValue in the package custom_interfaces.
typedef struct custom_interfaces__msg__WeighValue
{
  float value;
} custom_interfaces__msg__WeighValue;

// Struct for a sequence of custom_interfaces__msg__WeighValue.
typedef struct custom_interfaces__msg__WeighValue__Sequence
{
  custom_interfaces__msg__WeighValue * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__WeighValue__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__WEIGH_VALUE__STRUCT_H_
