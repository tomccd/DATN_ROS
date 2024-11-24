// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_interfaces:msg/SetStartStopPending.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_interfaces/msg/detail/set_start_stop_pending__functions.h"
#include "custom_interfaces/msg/detail/set_start_stop_pending__struct.hpp"
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

void SetStartStopPending_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_interfaces::msg::SetStartStopPending(_init);
}

void SetStartStopPending_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_interfaces::msg::SetStartStopPending *>(message_memory);
  typed_message->~SetStartStopPending();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SetStartStopPending_message_member_array[1] = {
  {
    "command",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces::msg::SetStartStopPending, command),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SetStartStopPending_message_members = {
  "custom_interfaces::msg",  // message namespace
  "SetStartStopPending",  // message name
  1,  // number of fields
  sizeof(custom_interfaces::msg::SetStartStopPending),
  false,  // has_any_key_member_
  SetStartStopPending_message_member_array,  // message members
  SetStartStopPending_init_function,  // function to initialize message memory (memory has to be allocated)
  SetStartStopPending_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SetStartStopPending_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SetStartStopPending_message_members,
  get_message_typesupport_handle_function,
  &custom_interfaces__msg__SetStartStopPending__get_type_hash,
  &custom_interfaces__msg__SetStartStopPending__get_type_description,
  &custom_interfaces__msg__SetStartStopPending__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_interfaces::msg::SetStartStopPending>()
{
  return &::custom_interfaces::msg::rosidl_typesupport_introspection_cpp::SetStartStopPending_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_interfaces, msg, SetStartStopPending)() {
  return &::custom_interfaces::msg::rosidl_typesupport_introspection_cpp::SetStartStopPending_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
