// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:srv/InitSys.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/srv/detail/init_sys__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `a`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_interfaces__srv__InitSys_Request__init(custom_interfaces__srv__InitSys_Request * msg)
{
  if (!msg) {
    return false;
  }
  // a
  if (!rosidl_runtime_c__String__init(&msg->a)) {
    custom_interfaces__srv__InitSys_Request__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__srv__InitSys_Request__fini(custom_interfaces__srv__InitSys_Request * msg)
{
  if (!msg) {
    return;
  }
  // a
  rosidl_runtime_c__String__fini(&msg->a);
}

bool
custom_interfaces__srv__InitSys_Request__are_equal(const custom_interfaces__srv__InitSys_Request * lhs, const custom_interfaces__srv__InitSys_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // a
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->a), &(rhs->a)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__srv__InitSys_Request__copy(
  const custom_interfaces__srv__InitSys_Request * input,
  custom_interfaces__srv__InitSys_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // a
  if (!rosidl_runtime_c__String__copy(
      &(input->a), &(output->a)))
  {
    return false;
  }
  return true;
}

custom_interfaces__srv__InitSys_Request *
custom_interfaces__srv__InitSys_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InitSys_Request * msg = (custom_interfaces__srv__InitSys_Request *)allocator.allocate(sizeof(custom_interfaces__srv__InitSys_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__srv__InitSys_Request));
  bool success = custom_interfaces__srv__InitSys_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__srv__InitSys_Request__destroy(custom_interfaces__srv__InitSys_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__srv__InitSys_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__srv__InitSys_Request__Sequence__init(custom_interfaces__srv__InitSys_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InitSys_Request * data = NULL;

  if (size) {
    data = (custom_interfaces__srv__InitSys_Request *)allocator.zero_allocate(size, sizeof(custom_interfaces__srv__InitSys_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__srv__InitSys_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__srv__InitSys_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__srv__InitSys_Request__Sequence__fini(custom_interfaces__srv__InitSys_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__srv__InitSys_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__srv__InitSys_Request__Sequence *
custom_interfaces__srv__InitSys_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InitSys_Request__Sequence * array = (custom_interfaces__srv__InitSys_Request__Sequence *)allocator.allocate(sizeof(custom_interfaces__srv__InitSys_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__srv__InitSys_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__srv__InitSys_Request__Sequence__destroy(custom_interfaces__srv__InitSys_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__srv__InitSys_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__srv__InitSys_Request__Sequence__are_equal(const custom_interfaces__srv__InitSys_Request__Sequence * lhs, const custom_interfaces__srv__InitSys_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__srv__InitSys_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__srv__InitSys_Request__Sequence__copy(
  const custom_interfaces__srv__InitSys_Request__Sequence * input,
  custom_interfaces__srv__InitSys_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__srv__InitSys_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__srv__InitSys_Request * data =
      (custom_interfaces__srv__InitSys_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__srv__InitSys_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__srv__InitSys_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__srv__InitSys_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `b`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
custom_interfaces__srv__InitSys_Response__init(custom_interfaces__srv__InitSys_Response * msg)
{
  if (!msg) {
    return false;
  }
  // b
  if (!rosidl_runtime_c__String__init(&msg->b)) {
    custom_interfaces__srv__InitSys_Response__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__srv__InitSys_Response__fini(custom_interfaces__srv__InitSys_Response * msg)
{
  if (!msg) {
    return;
  }
  // b
  rosidl_runtime_c__String__fini(&msg->b);
}

bool
custom_interfaces__srv__InitSys_Response__are_equal(const custom_interfaces__srv__InitSys_Response * lhs, const custom_interfaces__srv__InitSys_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // b
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->b), &(rhs->b)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__srv__InitSys_Response__copy(
  const custom_interfaces__srv__InitSys_Response * input,
  custom_interfaces__srv__InitSys_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // b
  if (!rosidl_runtime_c__String__copy(
      &(input->b), &(output->b)))
  {
    return false;
  }
  return true;
}

custom_interfaces__srv__InitSys_Response *
custom_interfaces__srv__InitSys_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InitSys_Response * msg = (custom_interfaces__srv__InitSys_Response *)allocator.allocate(sizeof(custom_interfaces__srv__InitSys_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__srv__InitSys_Response));
  bool success = custom_interfaces__srv__InitSys_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__srv__InitSys_Response__destroy(custom_interfaces__srv__InitSys_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__srv__InitSys_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__srv__InitSys_Response__Sequence__init(custom_interfaces__srv__InitSys_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InitSys_Response * data = NULL;

  if (size) {
    data = (custom_interfaces__srv__InitSys_Response *)allocator.zero_allocate(size, sizeof(custom_interfaces__srv__InitSys_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__srv__InitSys_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__srv__InitSys_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__srv__InitSys_Response__Sequence__fini(custom_interfaces__srv__InitSys_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__srv__InitSys_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__srv__InitSys_Response__Sequence *
custom_interfaces__srv__InitSys_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InitSys_Response__Sequence * array = (custom_interfaces__srv__InitSys_Response__Sequence *)allocator.allocate(sizeof(custom_interfaces__srv__InitSys_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__srv__InitSys_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__srv__InitSys_Response__Sequence__destroy(custom_interfaces__srv__InitSys_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__srv__InitSys_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__srv__InitSys_Response__Sequence__are_equal(const custom_interfaces__srv__InitSys_Response__Sequence * lhs, const custom_interfaces__srv__InitSys_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__srv__InitSys_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__srv__InitSys_Response__Sequence__copy(
  const custom_interfaces__srv__InitSys_Response__Sequence * input,
  custom_interfaces__srv__InitSys_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__srv__InitSys_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__srv__InitSys_Response * data =
      (custom_interfaces__srv__InitSys_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__srv__InitSys_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__srv__InitSys_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__srv__InitSys_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "custom_interfaces/srv/detail/init_sys__functions.h"

bool
custom_interfaces__srv__InitSys_Event__init(custom_interfaces__srv__InitSys_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    custom_interfaces__srv__InitSys_Event__fini(msg);
    return false;
  }
  // request
  if (!custom_interfaces__srv__InitSys_Request__Sequence__init(&msg->request, 0)) {
    custom_interfaces__srv__InitSys_Event__fini(msg);
    return false;
  }
  // response
  if (!custom_interfaces__srv__InitSys_Response__Sequence__init(&msg->response, 0)) {
    custom_interfaces__srv__InitSys_Event__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__srv__InitSys_Event__fini(custom_interfaces__srv__InitSys_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  custom_interfaces__srv__InitSys_Request__Sequence__fini(&msg->request);
  // response
  custom_interfaces__srv__InitSys_Response__Sequence__fini(&msg->response);
}

bool
custom_interfaces__srv__InitSys_Event__are_equal(const custom_interfaces__srv__InitSys_Event * lhs, const custom_interfaces__srv__InitSys_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!custom_interfaces__srv__InitSys_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!custom_interfaces__srv__InitSys_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__srv__InitSys_Event__copy(
  const custom_interfaces__srv__InitSys_Event * input,
  custom_interfaces__srv__InitSys_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!custom_interfaces__srv__InitSys_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!custom_interfaces__srv__InitSys_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

custom_interfaces__srv__InitSys_Event *
custom_interfaces__srv__InitSys_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InitSys_Event * msg = (custom_interfaces__srv__InitSys_Event *)allocator.allocate(sizeof(custom_interfaces__srv__InitSys_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__srv__InitSys_Event));
  bool success = custom_interfaces__srv__InitSys_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__srv__InitSys_Event__destroy(custom_interfaces__srv__InitSys_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__srv__InitSys_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__srv__InitSys_Event__Sequence__init(custom_interfaces__srv__InitSys_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InitSys_Event * data = NULL;

  if (size) {
    data = (custom_interfaces__srv__InitSys_Event *)allocator.zero_allocate(size, sizeof(custom_interfaces__srv__InitSys_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__srv__InitSys_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__srv__InitSys_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__srv__InitSys_Event__Sequence__fini(custom_interfaces__srv__InitSys_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__srv__InitSys_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__srv__InitSys_Event__Sequence *
custom_interfaces__srv__InitSys_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__srv__InitSys_Event__Sequence * array = (custom_interfaces__srv__InitSys_Event__Sequence *)allocator.allocate(sizeof(custom_interfaces__srv__InitSys_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__srv__InitSys_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__srv__InitSys_Event__Sequence__destroy(custom_interfaces__srv__InitSys_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__srv__InitSys_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__srv__InitSys_Event__Sequence__are_equal(const custom_interfaces__srv__InitSys_Event__Sequence * lhs, const custom_interfaces__srv__InitSys_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__srv__InitSys_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__srv__InitSys_Event__Sequence__copy(
  const custom_interfaces__srv__InitSys_Event__Sequence * input,
  custom_interfaces__srv__InitSys_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__srv__InitSys_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__srv__InitSys_Event * data =
      (custom_interfaces__srv__InitSys_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__srv__InitSys_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__srv__InitSys_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__srv__InitSys_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
