// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/SendFileName.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/send_file_name.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__SendFileName __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__SendFileName __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SendFileName_
{
  using Type = SendFileName_<ContainerAllocator>;

  explicit SendFileName_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fname = "";
    }
  }

  explicit SendFileName_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fname(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fname = "";
    }
  }

  // field types and members
  using _fname_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fname_type fname;

  // setters for named parameter idiom
  Type & set__fname(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fname = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::SendFileName_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::SendFileName_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::SendFileName_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::SendFileName_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::SendFileName_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::SendFileName_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::SendFileName_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::SendFileName_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::SendFileName_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::SendFileName_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__SendFileName
    std::shared_ptr<custom_interfaces::msg::SendFileName_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__SendFileName
    std::shared_ptr<custom_interfaces::msg::SendFileName_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SendFileName_ & other) const
  {
    if (this->fname != other.fname) {
      return false;
    }
    return true;
  }
  bool operator!=(const SendFileName_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SendFileName_

// alias to use template instance with default allocator
using SendFileName =
  custom_interfaces::msg::SendFileName_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SEND_FILE_NAME__STRUCT_HPP_
