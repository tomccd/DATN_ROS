// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/SetServoRotate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/set_servo_rotate.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_ROTATE__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_ROTATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/set_servo_rotate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetServoRotate & msg,
  std::ostream & out)
{
  out << "{";
  // member: rotatemsg
  {
    out << "rotatemsg: ";
    rosidl_generator_traits::value_to_yaml(msg.rotatemsg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetServoRotate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: rotatemsg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotatemsg: ";
    rosidl_generator_traits::value_to_yaml(msg.rotatemsg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetServoRotate & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::SetServoRotate & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::SetServoRotate & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::SetServoRotate>()
{
  return "custom_interfaces::msg::SetServoRotate";
}

template<>
inline const char * name<custom_interfaces::msg::SetServoRotate>()
{
  return "custom_interfaces/msg/SetServoRotate";
}

template<>
struct has_fixed_size<custom_interfaces::msg::SetServoRotate>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::SetServoRotate>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::SetServoRotate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_ROTATE__TRAITS_HPP_
