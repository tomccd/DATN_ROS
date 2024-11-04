// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/TerminateSys.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/terminate_sys.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE_SYS__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE_SYS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__TerminateSys __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__TerminateSys __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TerminateSys_
{
  using Type = TerminateSys_<ContainerAllocator>;

  explicit TerminateSys_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = "";
    }
  }

  explicit TerminateSys_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : a(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = "";
    }
  }

  // field types and members
  using _a_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _a_type a;

  // setters for named parameter idiom
  Type & set__a(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->a = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::TerminateSys_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::TerminateSys_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::TerminateSys_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::TerminateSys_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::TerminateSys_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::TerminateSys_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::TerminateSys_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::TerminateSys_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::TerminateSys_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::TerminateSys_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__TerminateSys
    std::shared_ptr<custom_interfaces::msg::TerminateSys_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__TerminateSys
    std::shared_ptr<custom_interfaces::msg::TerminateSys_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TerminateSys_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    return true;
  }
  bool operator!=(const TerminateSys_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TerminateSys_

// alias to use template instance with default allocator
using TerminateSys =
  custom_interfaces::msg::TerminateSys_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__TERMINATE_SYS__STRUCT_HPP_
