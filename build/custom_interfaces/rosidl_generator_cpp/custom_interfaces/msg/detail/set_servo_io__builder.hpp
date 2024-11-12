// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/SetServoIO.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/set_servo_io.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_IO__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_IO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/set_servo_io__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetServoIO_iomsg
{
public:
  Init_SetServoIO_iomsg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::SetServoIO iomsg(::custom_interfaces::msg::SetServoIO::_iomsg_type arg)
  {
    msg_.iomsg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::SetServoIO msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::SetServoIO>()
{
  return custom_interfaces::msg::builder::Init_SetServoIO_iomsg();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_IO__BUILDER_HPP_
