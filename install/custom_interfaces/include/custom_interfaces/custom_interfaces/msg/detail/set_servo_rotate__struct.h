// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/SetServoRotate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/set_servo_rotate.h"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_ROTATE__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_ROTATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'rotatemsg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SetServoRotate in the package custom_interfaces.
typedef struct custom_interfaces__msg__SetServoRotate
{
  rosidl_runtime_c__String rotatemsg;
} custom_interfaces__msg__SetServoRotate;

// Struct for a sequence of custom_interfaces__msg__SetServoRotate.
typedef struct custom_interfaces__msg__SetServoRotate__Sequence
{
  custom_interfaces__msg__SetServoRotate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__SetServoRotate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_ROTATE__STRUCT_H_
