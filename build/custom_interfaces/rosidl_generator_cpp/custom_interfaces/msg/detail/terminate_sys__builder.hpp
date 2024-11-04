// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/TerminateSys.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/terminate_sys.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE_SYS__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE_SYS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/terminate_sys__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_TerminateSys_a
{
public:
  Init_TerminateSys_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::TerminateSys a(::custom_interfaces::msg::TerminateSys::_a_type arg)
  {
    msg_.a = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::TerminateSys msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::TerminateSys>()
{
  return custom_interfaces::msg::builder::Init_TerminateSys_a();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE_SYS__BUILDER_HPP_
