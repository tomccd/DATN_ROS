// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/SetServoIO.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/set_servo_io__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__SetServoIO__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3e, 0xad, 0x9e, 0x01, 0xef, 0xea, 0xad, 0xe8,
      0x2a, 0x13, 0xac, 0x6f, 0x73, 0xff, 0xf4, 0x5b,
      0x0c, 0xed, 0x14, 0xb6, 0xdb, 0x6b, 0x3b, 0x63,
      0x35, 0xf1, 0x09, 0x22, 0x80, 0x00, 0xc8, 0x9f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__SetServoIO__TYPE_NAME[] = "custom_interfaces/msg/SetServoIO";

// Define type names, field names, and default values
static char custom_interfaces__msg__SetServoIO__FIELD_NAME__iomsg[] = "iomsg";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__SetServoIO__FIELDS[] = {
  {
    {custom_interfaces__msg__SetServoIO__FIELD_NAME__iomsg, 5, 5},
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
custom_interfaces__msg__SetServoIO__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__SetServoIO__TYPE_NAME, 32, 32},
      {custom_interfaces__msg__SetServoIO__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string iomsg";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__SetServoIO__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__SetServoIO__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 12, 12},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__SetServoIO__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__SetServoIO__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
