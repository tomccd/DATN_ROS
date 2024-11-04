// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Terminate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/terminate.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/terminate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Terminate_a
{
public:
  Init_Terminate_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::Terminate a(::custom_interfaces::msg::Terminate::_a_type arg)
  {
    msg_.a = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Terminate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Terminate>()
{
  return custom_interfaces::msg::builder::Init_Terminate_a();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE__BUILDER_HPP_
