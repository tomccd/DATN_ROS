// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/WeighValue.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/weigh_value.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__WEIGH_VALUE__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__WEIGH_VALUE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__WeighValue __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__WeighValue __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WeighValue_
{
  using Type = WeighValue_<ContainerAllocator>;

  explicit WeighValue_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0.0f;
    }
  }

  explicit WeighValue_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0.0f;
    }
  }

  // field types and members
  using _value_type =
    float;
  _value_type value;

  // setters for named parameter idiom
  Type & set__value(
    const float & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::WeighValue_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::WeighValue_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::WeighValue_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::WeighValue_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::WeighValue_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::WeighValue_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::WeighValue_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::WeighValue_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::WeighValue_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::WeighValue_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__WeighValue
    std::shared_ptr<custom_interfaces::msg::WeighValue_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__WeighValue
    std::shared_ptr<custom_interfaces::msg::WeighValue_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WeighValue_ & other) const
  {
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const WeighValue_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WeighValue_

// alias to use template instance with default allocator
using WeighValue =
  custom_interfaces::msg::WeighValue_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__WEIGH_VALUE__STRUCT_HPP_
