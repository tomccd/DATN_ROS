// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_interfaces:msg/SetServoIO.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_interfaces/msg/detail/set_servo_io__functions.h"
#include "custom_interfaces/msg/detail/set_servo_io__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SetServoIO_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_interfaces::msg::SetServoIO(_init);
}

void SetServoIO_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_interfaces::msg::SetServoIO *>(message_memory);
  typed_message->~SetServoIO();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SetServoIO_message_member_array[1] = {
  {
    "iomsg",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces::msg::SetServoIO, iomsg),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SetServoIO_message_members = {
  "custom_interfaces::msg",  // message namespace
  "SetServoIO",  // message name
  1,  // number of fields
  sizeof(custom_interfaces::msg::SetServoIO),
  false,  // has_any_key_member_
  SetServoIO_message_member_array,  // message members
  SetServoIO_init_function,  // function to initialize message memory (memory has to be allocated)
  SetServoIO_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SetServoIO_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SetServoIO_message_members,
  get_message_typesupport_handle_function,
  &custom_interfaces__msg__SetServoIO__get_type_hash,
  &custom_interfaces__msg__SetServoIO__get_type_description,
  &custom_interfaces__msg__SetServoIO__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_interfaces::msg::SetServoIO>()
{
  return &::custom_interfaces::msg::rosidl_typesupport_introspection_cpp::SetServoIO_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_interfaces, msg, SetServoIO)() {
  return &::custom_interfaces::msg::rosidl_typesupport_introspection_cpp::SetServoIO_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
