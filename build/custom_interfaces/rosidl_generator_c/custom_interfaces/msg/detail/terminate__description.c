// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/Terminate.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/terminate__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__Terminate__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xeb, 0x56, 0x4a, 0x95, 0xa6, 0x32, 0x08, 0x33,
      0xcf, 0xd5, 0x9e, 0xb7, 0x96, 0xdb, 0xdb, 0xe2,
      0xa7, 0x35, 0x35, 0xc8, 0x2a, 0x1c, 0x70, 0x82,
      0x9b, 0xdb, 0x8d, 0x02, 0xd2, 0x64, 0xe2, 0x12,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__Terminate__TYPE_NAME[] = "custom_interfaces/msg/Terminate";

// Define type names, field names, and default values
static char custom_interfaces__msg__Terminate__FIELD_NAME__a[] = "a";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__Terminate__FIELDS[] = {
  {
    {custom_interfaces__msg__Terminate__FIELD_NAME__a, 1, 1},
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
custom_interfaces__msg__Terminate__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__Terminate__TYPE_NAME, 31, 31},
      {custom_interfaces__msg__Terminate__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string a";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__Terminate__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__Terminate__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 8, 8},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__Terminate__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__Terminate__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
