// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/SetWeighIO.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/set_weigh_io.h"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_WEIGH_IO__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_WEIGH_IO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/SetWeighIO in the package custom_interfaces.
typedef struct custom_interfaces__msg__SetWeighIO
{
  bool status;
} custom_interfaces__msg__SetWeighIO;

// Struct for a sequence of custom_interfaces__msg__SetWeighIO.
typedef struct custom_interfaces__msg__SetWeighIO__Sequence
{
  custom_interfaces__msg__SetWeighIO * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__SetWeighIO__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_WEIGH_IO__STRUCT_H_
