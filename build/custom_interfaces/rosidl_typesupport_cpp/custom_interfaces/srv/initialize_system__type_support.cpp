// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from custom_interfaces:srv/InitializeSystem.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "custom_interfaces/srv/detail/initialize_system__functions.h"
#include "custom_interfaces/srv/detail/initialize_system__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace custom_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _InitializeSystem_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _InitializeSystem_Request_type_support_ids_t;

static const _InitializeSystem_Request_type_support_ids_t _InitializeSystem_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _InitializeSystem_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _InitializeSystem_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _InitializeSystem_Request_type_support_symbol_names_t _InitializeSystem_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_interfaces, srv, InitializeSystem_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_interfaces, srv, InitializeSystem_Request)),
  }
};

typedef struct _InitializeSystem_Request_type_support_data_t
{
  void * data[2];
} _InitializeSystem_Request_type_support_data_t;

static _InitializeSystem_Request_type_support_data_t _InitializeSystem_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _InitializeSystem_Request_message_typesupport_map = {
  2,
  "custom_interfaces",
  &_InitializeSystem_Request_message_typesupport_ids.typesupport_identifier[0],
  &_InitializeSystem_Request_message_typesupport_symbol_names.symbol_name[0],
  &_InitializeSystem_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t InitializeSystem_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_InitializeSystem_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &custom_interfaces__srv__InitializeSystem_Request__get_type_hash,
  &custom_interfaces__srv__InitializeSystem_Request__get_type_description,
  &custom_interfaces__srv__InitializeSystem_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_interfaces::srv::InitializeSystem_Request>()
{
  return &::custom_interfaces::srv::rosidl_typesupport_cpp::InitializeSystem_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_interfaces, srv, InitializeSystem_Request)() {
  return get_message_type_support_handle<custom_interfaces::srv::InitializeSystem_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_interfaces/srv/detail/initialize_system__functions.h"
// already included above
// #include "custom_interfaces/srv/detail/initialize_system__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _InitializeSystem_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _InitializeSystem_Response_type_support_ids_t;

static const _InitializeSystem_Response_type_support_ids_t _InitializeSystem_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _InitializeSystem_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _InitializeSystem_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _InitializeSystem_Response_type_support_symbol_names_t _InitializeSystem_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_interfaces, srv, InitializeSystem_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_interfaces, srv, InitializeSystem_Response)),
  }
};

typedef struct _InitializeSystem_Response_type_support_data_t
{
  void * data[2];
} _InitializeSystem_Response_type_support_data_t;

static _InitializeSystem_Response_type_support_data_t _InitializeSystem_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _InitializeSystem_Response_message_typesupport_map = {
  2,
  "custom_interfaces",
  &_InitializeSystem_Response_message_typesupport_ids.typesupport_identifier[0],
  &_InitializeSystem_Response_message_typesupport_symbol_names.symbol_name[0],
  &_InitializeSystem_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t InitializeSystem_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_InitializeSystem_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &custom_interfaces__srv__InitializeSystem_Response__get_type_hash,
  &custom_interfaces__srv__InitializeSystem_Response__get_type_description,
  &custom_interfaces__srv__InitializeSystem_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_interfaces::srv::InitializeSystem_Response>()
{
  return &::custom_interfaces::srv::rosidl_typesupport_cpp::InitializeSystem_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_interfaces, srv, InitializeSystem_Response)() {
  return get_message_type_support_handle<custom_interfaces::srv::InitializeSystem_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_interfaces/srv/detail/initialize_system__functions.h"
// already included above
// #include "custom_interfaces/srv/detail/initialize_system__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _InitializeSystem_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _InitializeSystem_Event_type_support_ids_t;

static const _InitializeSystem_Event_type_support_ids_t _InitializeSystem_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _InitializeSystem_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _InitializeSystem_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _InitializeSystem_Event_type_support_symbol_names_t _InitializeSystem_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_interfaces, srv, InitializeSystem_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_interfaces, srv, InitializeSystem_Event)),
  }
};

typedef struct _InitializeSystem_Event_type_support_data_t
{
  void * data[2];
} _InitializeSystem_Event_type_support_data_t;

static _InitializeSystem_Event_type_support_data_t _InitializeSystem_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _InitializeSystem_Event_message_typesupport_map = {
  2,
  "custom_interfaces",
  &_InitializeSystem_Event_message_typesupport_ids.typesupport_identifier[0],
  &_InitializeSystem_Event_message_typesupport_symbol_names.symbol_name[0],
  &_InitializeSystem_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t InitializeSystem_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_InitializeSystem_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &custom_interfaces__srv__InitializeSystem_Event__get_type_hash,
  &custom_interfaces__srv__InitializeSystem_Event__get_type_description,
  &custom_interfaces__srv__InitializeSystem_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_interfaces::srv::InitializeSystem_Event>()
{
  return &::custom_interfaces::srv::rosidl_typesupport_cpp::InitializeSystem_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_interfaces, srv, InitializeSystem_Event)() {
  return get_message_type_support_handle<custom_interfaces::srv::InitializeSystem_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "custom_interfaces/srv/detail/initialize_system__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _InitializeSystem_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _InitializeSystem_type_support_ids_t;

static const _InitializeSystem_type_support_ids_t _InitializeSystem_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _InitializeSystem_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _InitializeSystem_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _InitializeSystem_type_support_symbol_names_t _InitializeSystem_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_interfaces, srv, InitializeSystem)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_interfaces, srv, InitializeSystem)),
  }
};

typedef struct _InitializeSystem_type_support_data_t
{
  void * data[2];
} _InitializeSystem_type_support_data_t;

static _InitializeSystem_type_support_data_t _InitializeSystem_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _InitializeSystem_service_typesupport_map = {
  2,
  "custom_interfaces",
  &_InitializeSystem_service_typesupport_ids.typesupport_identifier[0],
  &_InitializeSystem_service_typesupport_symbol_names.symbol_name[0],
  &_InitializeSystem_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t InitializeSystem_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_InitializeSystem_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<custom_interfaces::srv::InitializeSystem_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<custom_interfaces::srv::InitializeSystem_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<custom_interfaces::srv::InitializeSystem_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<custom_interfaces::srv::InitializeSystem>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<custom_interfaces::srv::InitializeSystem>,
  &custom_interfaces__srv__InitializeSystem__get_type_hash,
  &custom_interfaces__srv__InitializeSystem__get_type_description,
  &custom_interfaces__srv__InitializeSystem__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<custom_interfaces::srv::InitializeSystem>()
{
  return &::custom_interfaces::srv::rosidl_typesupport_cpp::InitializeSystem_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_interfaces, srv, InitializeSystem)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<custom_interfaces::srv::InitializeSystem>();
}

#ifdef __cplusplus
}
#endif
