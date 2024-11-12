// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/SendFileName.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/send_file_name.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/send_file_name__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SendFileName & msg,
  std::ostream & out)
{
  out << "{";
  // member: fname
  {
    out << "fname: ";
    rosidl_generator_traits::value_to_yaml(msg.fname, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SendFileName & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: fname
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fname: ";
    rosidl_generator_traits::value_to_yaml(msg.fname, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SendFileName & msg, bool use_flow_style = false)
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
  const custom_interfaces::msg::SendFileName & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::SendFileName & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::SendFileName>()
{
  return "custom_interfaces::msg::SendFileName";
}

template<>
inline const char * name<custom_interfaces::msg::SendFileName>()
{
  return "custom_interfaces/msg/SendFileName";
}

template<>
struct has_fixed_size<custom_interfaces::msg::SendFileName>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::SendFileName>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::SendFileName>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__TRAITS_HPP_
