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

#include <stdbool.h>
#include <stdint.h>


#include "util/list.h"

struct pebble_mutex_t;
typedef struct pebble_mutex_t PebbleMutex;
struct pebble_recursive_mutex_t;
typedef struct pebble_recursive_mutex_t PebbleRecursiveMutex;

#define INVALID_MUTEX_HANDLE 0

//! @return INVALID_MUTEX_HANDLE if failed, success otherwise.
PebbleMutex *mutex_create(void);

void mutex_destroy(PebbleMutex *handle);

void mutex_lock(PebbleMutex *handle);

bool mutex_lock_with_timeout(PebbleMutex *handle, uint32_t timeout_ms);

void mutex_lock_with_lr(PebbleMutex *handle, uint32_t myLR);

void mutex_unlock(PebbleMutex *handle);

PebbleRecursiveMutex * mutex_create_recursive(void);

void mutex_lock_recursive(PebbleRecursiveMutex *handle);

bool mutex_lock_recursive_with_timeout(PebbleRecursiveMutex *handle, uint32_t timeout_ms);

bool mutex_lock_recursive_with_timeout_and_lr(PebbleRecursiveMutex *handle,
                                              uint32_t timeout_ms,
                                              uint32_t LR);

//! Tests if a given mutex is owned by the current task. Useful for
//! ensuring locks are held when they should be.
bool mutex_is_owned_recursive(PebbleRecursiveMutex *handle);

void mutex_unlock_recursive(PebbleRecursiveMutex *handle);

//! @return true if the calling task owns the mutex
void mutex_assert_held_by_curr_task(PebbleMutex *handle, bool is_held);

//! @return true if the calling task owns the mutex
void mutex_assert_recursive_held_by_curr_task(PebbleRecursiveMutex *handle, bool is_held);
