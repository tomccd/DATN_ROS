// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/SetServoIO.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/set_servo_io.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_IO__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_IO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__SetServoIO __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__SetServoIO __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SetServoIO_
{
  using Type = SetServoIO_<ContainerAllocator>;

  explicit SetServoIO_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->iomsg = "";
    }
  }

  explicit SetServoIO_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : iomsg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->iomsg = "";
    }
  }

  // field types and members
  using _iomsg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _iomsg_type iomsg;

  // setters for named parameter idiom
  Type & set__iomsg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->iomsg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::SetServoIO_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::SetServoIO_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::SetServoIO_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::SetServoIO_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::SetServoIO_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::SetServoIO_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::SetServoIO_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::SetServoIO_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::SetServoIO_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::SetServoIO_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__SetServoIO
    std::shared_ptr<custom_interfaces::msg::SetServoIO_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__SetServoIO
    std::shared_ptr<custom_interfaces::msg::SetServoIO_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetServoIO_ & other) const
  {
    if (this->iomsg != other.iomsg) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetServoIO_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetServoIO_

// alias to use template instance with default allocator
using SetServoIO =
  custom_interfaces::msg::SetServoIO_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_SERVO_IO__STRUCT_HPP_
