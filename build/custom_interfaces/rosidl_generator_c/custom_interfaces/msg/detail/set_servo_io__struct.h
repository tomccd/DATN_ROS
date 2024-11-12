// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/SetServoIO.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/set_servo_io.h"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_IO__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_IO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'iomsg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SetServoIO in the package custom_interfaces.
typedef struct custom_interfaces__msg__SetServoIO
{
  rosidl_runtime_c__String iomsg;
} custom_interfaces__msg__SetServoIO;

// Struct for a sequence of custom_interfaces__msg__SetServoIO.
typedef struct custom_interfaces__msg__SetServoIO__Sequence
{
  custom_interfaces__msg__SetServoIO * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__SetServoIO__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_IO__STRUCT_H_
