/*
 * Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

struct pebble_mutex_t {
  void *foo;
};

struct pebble_recursive_mutex_t {
  int foo;
};

typedef struct pebble_mutex_t PebbleMutex;
typedef struct pebble_recursive_mutex_t PebbleRecursiveMutex;

PebbleMutex *mutex_create(void) {
  PebbleMutex *mutex = (void *)1;
  return (mutex);
}

void mutex_destroy(PebbleMutex *handle) {
  return;
}

void mutex_lock(PebbleMutex *handle) {
  return;
}

bool mutex_lock_with_timeout(PebbleMutex *handle, uint32_t timeout_ms) {
  return true;
}

void mutex_lock_with_lr(PebbleMutex * handle, uint32_t myLR) {
}

void mutex_unlock(PebbleMutex *handle) {
  return;
}

PebbleRecursiveMutex *mutex_create_recursive(void) {
  PebbleRecursiveMutex *mutex = (void *)1;
  return (mutex);
}

void mutex_lock_recursive(PebbleRecursiveMutex *handle) {
  return;
}

bool mutex_lock_recursive_with_timeout(PebbleRecursiveMutex *handle, uint32_t timeout_ms) {
  return true;
}

bool mutex_is_owned_recursive(PebbleRecursiveMutex *handle) {
  return true;
}

void mutex_unlock_recursive(PebbleRecursiveMutex *handle) {
  return;
}

void mutex_assert_held_by_curr_task(PebbleMutex * handle, bool is_held) {
}

void mutex_assert_recursive_held_by_curr_task(PebbleRecursiveMutex * handle, bool is_held) {
}
