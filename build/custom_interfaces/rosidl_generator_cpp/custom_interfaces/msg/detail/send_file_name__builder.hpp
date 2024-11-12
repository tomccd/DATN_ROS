// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/SendFileName.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/send_file_name.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/send_file_name__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_SendFileName_fname
{
public:
  Init_SendFileName_fname()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::SendFileName fname(::custom_interfaces::msg::SendFileName::_fname_type arg)
  {
    msg_.fname = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::SendFileName msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::SendFileName>()
{
  return custom_interfaces::msg::builder::Init_SendFileName_fname();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__BUILDER_HPP_
