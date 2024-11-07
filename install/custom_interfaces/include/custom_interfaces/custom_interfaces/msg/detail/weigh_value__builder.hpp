// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/WeighValue.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/weigh_value.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__WEIGH_VALUE__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__WEIGH_VALUE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/weigh_value__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_WeighValue_value
{
public:
  Init_WeighValue_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::WeighValue value(::custom_interfaces::msg::WeighValue::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::WeighValue msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::WeighValue>()
{
  return custom_interfaces::msg::builder::Init_WeighValue_value();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__WEIGH_VALUE__BUILDER_HPP_
