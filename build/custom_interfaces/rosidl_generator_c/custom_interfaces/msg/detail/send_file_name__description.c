// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/SendFileName.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/send_file_name__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__SendFileName__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe8, 0xf3, 0x8c, 0x39, 0x73, 0x16, 0x3b, 0x7c,
      0xe5, 0xa1, 0x6b, 0x9d, 0x1e, 0x16, 0xe1, 0x95,
      0xc3, 0x26, 0x65, 0x39, 0x68, 0xa5, 0x4c, 0xf2,
      0xe9, 0x6a, 0x0e, 0x71, 0xfc, 0x7a, 0x79, 0x4b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__SendFileName__TYPE_NAME[] = "custom_interfaces/msg/SendFileName";

// Define type names, field names, and default values
static char custom_interfaces__msg__SendFileName__FIELD_NAME__fname[] = "fname";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__SendFileName__FIELDS[] = {
  {
    {custom_interfaces__msg__SendFileName__FIELD_NAME__fname, 5, 5},
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
custom_interfaces__msg__SendFileName__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__SendFileName__TYPE_NAME, 34, 34},
      {custom_interfaces__msg__SendFileName__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string fname";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__SendFileName__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__SendFileName__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 12, 12},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__SendFileName__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__SendFileName__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
