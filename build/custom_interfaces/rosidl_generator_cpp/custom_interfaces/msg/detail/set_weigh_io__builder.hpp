// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/SetWeighIO.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/set_weigh_io.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_WEIGH_IO__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_WEIGH_IO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/set_weigh_io__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetWeighIO_status
{
public:
  Init_SetWeighIO_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::SetWeighIO status(::custom_interfaces::msg::SetWeighIO::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::SetWeighIO msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::SetWeighIO>()
{
  return custom_interfaces::msg::builder::Init_SetWeighIO_status();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_WEIGH_IO__BUILDER_HPP_
