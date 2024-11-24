// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/SetStartStopPending.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/set_start_stop_pending.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_START_STOP_PENDING__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_START_STOP_PENDING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/set_start_stop_pending__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetStartStopPending_command
{
public:
  Init_SetStartStopPending_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::SetStartStopPending command(::custom_interfaces::msg::SetStartStopPending::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::SetStartStopPending msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::SetStartStopPending>()
{
  return custom_interfaces::msg::builder::Init_SetStartStopPending_command();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_START_STOP_PENDING__BUILDER_HPP_
