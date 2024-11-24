// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/SetStartStopPending.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/set_start_stop_pending__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__SetStartStopPending__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x48, 0x96, 0x54, 0xc9, 0xdf, 0x09, 0x76, 0x40,
      0xbe, 0xfa, 0xd9, 0x23, 0xb3, 0x84, 0xa2, 0x36,
      0x6f, 0x13, 0x91, 0x9e, 0x7d, 0x7e, 0xea, 0xb7,
      0x82, 0x88, 0xa8, 0x4b, 0xa8, 0xcb, 0xc2, 0xc5,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__SetStartStopPending__TYPE_NAME[] = "custom_interfaces/msg/SetStartStopPending";

// Define type names, field names, and default values
static char custom_interfaces__msg__SetStartStopPending__FIELD_NAME__command[] = "command";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__SetStartStopPending__FIELDS[] = {
  {
    {custom_interfaces__msg__SetStartStopPending__FIELD_NAME__command, 7, 7},
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
custom_interfaces__msg__SetStartStopPending__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__SetStartStopPending__TYPE_NAME, 41, 41},
      {custom_interfaces__msg__SetStartStopPending__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string command";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__SetStartStopPending__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__SetStartStopPending__TYPE_NAME, 41, 41},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 14, 14},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__SetStartStopPending__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__SetStartStopPending__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
