// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_interfaces:msg/SetServoRotate.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/set_servo_rotate__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_interfaces/msg/detail/set_servo_rotate__struct.h"
#include "custom_interfaces/msg/detail/set_servo_rotate__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // rotatemsg
#include "rosidl_runtime_c/string_functions.h"  // rotatemsg

// forward declare type support functions


using _SetServoRotate__ros_msg_type = custom_interfaces__msg__SetServoRotate;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_custom_interfaces__msg__SetServoRotate(
  const custom_interfaces__msg__SetServoRotate * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: rotatemsg
  {
    const rosidl_runtime_c__String * str = &ros_message->rotatemsg;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_deserialize_custom_interfaces__msg__SetServoRotate(
  eprosima::fastcdr::Cdr & cdr,
  custom_interfaces__msg__SetServoRotate * ros_message)
{
  // Field name: rotatemsg
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->rotatemsg.data) {
      rosidl_runtime_c__String__init(&ros_message->rotatemsg);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->rotatemsg,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'rotatemsg'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t get_serialized_size_custom_interfaces__msg__SetServoRotate(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetServoRotate__ros_msg_type * ros_message = static_cast<const _SetServoRotate__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: rotatemsg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->rotatemsg.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t max_serialized_size_custom_interfaces__msg__SetServoRotate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: rotatemsg
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_interfaces__msg__SetServoRotate;
    is_plain =
      (
      offsetof(DataType, rotatemsg) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
bool cdr_serialize_key_custom_interfaces__msg__SetServoRotate(
  const custom_interfaces__msg__SetServoRotate * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: rotatemsg
  {
    const rosidl_runtime_c__String * str = &ros_message->rotatemsg;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t get_serialized_size_key_custom_interfaces__msg__SetServoRotate(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetServoRotate__ros_msg_type * ros_message = static_cast<const _SetServoRotate__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: rotatemsg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->rotatemsg.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_interfaces
size_t max_serialized_size_key_custom_interfaces__msg__SetServoRotate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: rotatemsg
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_interfaces__msg__SetServoRotate;
    is_plain =
      (
      offsetof(DataType, rotatemsg) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _SetServoRotate__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const custom_interfaces__msg__SetServoRotate * ros_message = static_cast<const custom_interfaces__msg__SetServoRotate *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_custom_interfaces__msg__SetServoRotate(ros_message, cdr);
}

static bool _SetServoRotate__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  custom_interfaces__msg__SetServoRotate * ros_message = static_cast<custom_interfaces__msg__SetServoRotate *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_custom_interfaces__msg__SetServoRotate(cdr, ros_message);
}

static uint32_t _SetServoRotate__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_interfaces__msg__SetServoRotate(
      untyped_ros_message, 0));
}

static size_t _SetServoRotate__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_interfaces__msg__SetServoRotate(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SetServoRotate = {
  "custom_interfaces::msg",
  "SetServoRotate",
  _SetServoRotate__cdr_serialize,
  _SetServoRotate__cdr_deserialize,
  _SetServoRotate__get_serialized_size,
  _SetServoRotate__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetServoRotate__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetServoRotate,
  get_message_typesupport_handle_function,
  &custom_interfaces__msg__SetServoRotate__get_type_hash,
  &custom_interfaces__msg__SetServoRotate__get_type_description,
  &custom_interfaces__msg__SetServoRotate__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_interfaces, msg, SetServoRotate)() {
  return &_SetServoRotate__type_support;
}

#if defined(__cplusplus)
}
#endif
