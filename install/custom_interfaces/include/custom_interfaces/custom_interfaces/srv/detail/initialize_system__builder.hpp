// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/InitializeSystem.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/initialize_system.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__INITIALIZE_SYSTEM__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__INITIALIZE_SYSTEM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/initialize_system__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_InitializeSystem_Request_a
{
public:
  Init_InitializeSystem_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::InitializeSystem_Request a(::custom_interfaces::srv::InitializeSystem_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::InitializeSystem_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::InitializeSystem_Request>()
{
  return custom_interfaces::srv::builder::Init_InitializeSystem_Request_a();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_InitializeSystem_Response_b
{
public:
  Init_InitializeSystem_Response_b()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::InitializeSystem_Response b(::custom_interfaces::srv::InitializeSystem_Response::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::InitializeSystem_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::InitializeSystem_Response>()
{
  return custom_interfaces::srv::builder::Init_InitializeSystem_Response_b();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_InitializeSystem_Event_response
{
public:
  explicit Init_InitializeSystem_Event_response(::custom_interfaces::srv::InitializeSystem_Event & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::InitializeSystem_Event response(::custom_interfaces::srv::InitializeSystem_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::InitializeSystem_Event msg_;
};

class Init_InitializeSystem_Event_request
{
public:
  explicit Init_InitializeSystem_Event_request(::custom_interfaces::srv::InitializeSystem_Event & msg)
  : msg_(msg)
  {}
  Init_InitializeSystem_Event_response request(::custom_interfaces::srv::InitializeSystem_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_InitializeSystem_Event_response(msg_);
  }

private:
  ::custom_interfaces::srv::InitializeSystem_Event msg_;
};

class Init_InitializeSystem_Event_info
{
public:
  Init_InitializeSystem_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InitializeSystem_Event_request info(::custom_interfaces::srv::InitializeSystem_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_InitializeSystem_Event_request(msg_);
  }

private:
  ::custom_interfaces::srv::InitializeSystem_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::InitializeSystem_Event>()
{
  return custom_interfaces::srv::builder::Init_InitializeSystem_Event_info();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__INITIALIZE_SYSTEM__BUILDER_HPP_
