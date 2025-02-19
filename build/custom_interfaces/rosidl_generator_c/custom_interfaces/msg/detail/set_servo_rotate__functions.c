// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/SetServoRotate.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/set_servo_rotate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `rotatemsg`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_interfaces__msg__SetServoRotate__init(custom_interfaces__msg__SetServoRotate * msg)
{
  if (!msg) {
    return false;
  }
  // rotatemsg
  if (!rosidl_runtime_c__String__init(&msg->rotatemsg)) {
    custom_interfaces__msg__SetServoRotate__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__msg__SetServoRotate__fini(custom_interfaces__msg__SetServoRotate * msg)
{
  if (!msg) {
    return;
  }
  // rotatemsg
  rosidl_runtime_c__String__fini(&msg->rotatemsg);
}

bool
custom_interfaces__msg__SetServoRotate__are_equal(const custom_interfaces__msg__SetServoRotate * lhs, const custom_interfaces__msg__SetServoRotate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // rotatemsg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->rotatemsg), &(rhs->rotatemsg)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__SetServoRotate__copy(
  const custom_interfaces__msg__SetServoRotate * input,
  custom_interfaces__msg__SetServoRotate * output)
{
  if (!input || !output) {
    return false;
  }
  // rotatemsg
  if (!rosidl_runtime_c__String__copy(
      &(input->rotatemsg), &(output->rotatemsg)))
  {
    return false;
  }
  return true;
}

custom_interfaces__msg__SetServoRotate *
custom_interfaces__msg__SetServoRotate__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__SetServoRotate * msg = (custom_interfaces__msg__SetServoRotate *)allocator.allocate(sizeof(custom_interfaces__msg__SetServoRotate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__SetServoRotate));
  bool success = custom_interfaces__msg__SetServoRotate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__SetServoRotate__destroy(custom_interfaces__msg__SetServoRotate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__SetServoRotate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__SetServoRotate__Sequence__init(custom_interfaces__msg__SetServoRotate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__SetServoRotate * data = NULL;

  if (size) {
    data = (custom_interfaces__msg__SetServoRotate *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__SetServoRotate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__SetServoRotate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__SetServoRotate__fini(&data[i - 1]);
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
custom_interfaces__msg__SetServoRotate__Sequence__fini(custom_interfaces__msg__SetServoRotate__Sequence * array)
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
      custom_interfaces__msg__SetServoRotate__fini(&array->data[i]);
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

custom_interfaces__msg__SetServoRotate__Sequence *
custom_interfaces__msg__SetServoRotate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__SetServoRotate__Sequence * array = (custom_interfaces__msg__SetServoRotate__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__SetServoRotate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__SetServoRotate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__SetServoRotate__Sequence__destroy(custom_interfaces__msg__SetServoRotate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__SetServoRotate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__SetServoRotate__Sequence__are_equal(const custom_interfaces__msg__SetServoRotate__Sequence * lhs, const custom_interfaces__msg__SetServoRotate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__SetServoRotate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__SetServoRotate__Sequence__copy(
  const custom_interfaces__msg__SetServoRotate__Sequence * input,
  custom_interfaces__msg__SetServoRotate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__SetServoRotate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__SetServoRotate * data =
      (custom_interfaces__msg__SetServoRotate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__SetServoRotate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__SetServoRotate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__SetServoRotate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
