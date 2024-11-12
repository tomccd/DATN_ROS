// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/SetServoRotate.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/set_servo_rotate__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__SetServoRotate__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdf, 0x3e, 0x5f, 0x0c, 0x8b, 0x28, 0x15, 0x4a,
      0xf7, 0xc3, 0x2c, 0xdb, 0x13, 0xbd, 0x9a, 0x47,
      0x37, 0x7f, 0xc4, 0x48, 0xd9, 0x60, 0x5d, 0x57,
      0x91, 0x34, 0xd4, 0x28, 0xf6, 0xe2, 0x4c, 0xca,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__SetServoRotate__TYPE_NAME[] = "custom_interfaces/msg/SetServoRotate";

// Define type names, field names, and default values
static char custom_interfaces__msg__SetServoRotate__FIELD_NAME__rotatemsg[] = "rotatemsg";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__SetServoRotate__FIELDS[] = {
  {
    {custom_interfaces__msg__SetServoRotate__FIELD_NAME__rotatemsg, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__msg__SetServoRotate__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__SetServoRotate__TYPE_NAME, 36, 36},
      {custom_interfaces__msg__SetServoRotate__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string rotatemsg";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__SetServoRotate__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__SetServoRotate__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 16, 16},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__SetServoRotate__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__SetServoRotate__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
