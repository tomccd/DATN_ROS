// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/SetWeighIO.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/set_weigh_io__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__SetWeighIO__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa7, 0x52, 0x13, 0x0b, 0xf6, 0xc8, 0x3f, 0x35,
      0x08, 0x58, 0x01, 0xd5, 0x30, 0x16, 0xfa, 0x04,
      0xec, 0x83, 0xc4, 0x46, 0xde, 0xc7, 0x54, 0xcb,
      0x04, 0x70, 0x0e, 0xd6, 0xed, 0x25, 0x97, 0x89,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__SetWeighIO__TYPE_NAME[] = "custom_interfaces/msg/SetWeighIO";

// Define type names, field names, and default values
static char custom_interfaces__msg__SetWeighIO__FIELD_NAME__status[] = "status";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__SetWeighIO__FIELDS[] = {
  {
    {custom_interfaces__msg__SetWeighIO__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__msg__SetWeighIO__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__SetWeighIO__TYPE_NAME, 32, 32},
      {custom_interfaces__msg__SetWeighIO__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool status";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__SetWeighIO__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__SetWeighIO__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 11, 11},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__SetWeighIO__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__SetWeighIO__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
