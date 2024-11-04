// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/TerminateSys.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/terminate_sys__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__TerminateSys__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaa, 0x78, 0xf3, 0x2c, 0x4d, 0xbb, 0x41, 0xc0,
      0xc0, 0x08, 0xf6, 0xc0, 0x8c, 0xb1, 0xf5, 0x63,
      0x43, 0xc5, 0xd8, 0x5c, 0xe8, 0x89, 0xba, 0xae,
      0x47, 0x84, 0xe3, 0x00, 0xc3, 0x33, 0x6b, 0x9f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__TerminateSys__TYPE_NAME[] = "custom_interfaces/msg/TerminateSys";

// Define type names, field names, and default values
static char custom_interfaces__msg__TerminateSys__FIELD_NAME__a[] = "a";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__TerminateSys__FIELDS[] = {
  {
    {custom_interfaces__msg__TerminateSys__FIELD_NAME__a, 1, 1},
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
custom_interfaces__msg__TerminateSys__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__TerminateSys__TYPE_NAME, 34, 34},
      {custom_interfaces__msg__TerminateSys__FIELDS, 1, 1},
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
custom_interfaces__msg__TerminateSys__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__TerminateSys__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 8, 8},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__TerminateSys__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__TerminateSys__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
