// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/WeighValue.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/weigh_value__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__WeighValue__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x71, 0x59, 0xd9, 0x6e, 0x20, 0x44, 0x3f, 0x9a,
      0x6c, 0x4c, 0x10, 0x81, 0x91, 0x4a, 0x48, 0x64,
      0xf8, 0x0f, 0xb9, 0x2f, 0xfe, 0xfd, 0x80, 0x2e,
      0x48, 0xb6, 0xd8, 0x3c, 0x2f, 0x0d, 0x3e, 0xac,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__WeighValue__TYPE_NAME[] = "custom_interfaces/msg/WeighValue";

// Define type names, field names, and default values
static char custom_interfaces__msg__WeighValue__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__WeighValue__FIELDS[] = {
  {
    {custom_interfaces__msg__WeighValue__FIELD_NAME__value, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__msg__WeighValue__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__WeighValue__TYPE_NAME, 32, 32},
      {custom_interfaces__msg__WeighValue__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 value";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__WeighValue__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__WeighValue__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 13, 13},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__WeighValue__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__WeighValue__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
