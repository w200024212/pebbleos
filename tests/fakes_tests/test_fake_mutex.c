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

#include "clar.h"

#include "fake_mutex.h"

#include <os/mutex.h>

void test_fake_mutex__initialize(void) {
}

void test_fake_mutex__cleanup(void) {
  const bool assert_all_unlocked = false;
  fake_mutex_reset(assert_all_unlocked);
}

void test_fake_mutex__normal_mutex(void) {
  PebbleMutex *mutex = mutex_create();
  mutex_lock(mutex);
  mutex_unlock(mutex);
  cl_assert_equal_b(fake_mutex_all_unlocked(), true);
}

void test_fake_mutex__leave_unlocked(void) {
  PebbleMutex *mutex = mutex_create();
  mutex_lock(mutex);
  cl_assert_equal_b(fake_mutex_all_unlocked(), false);
}

void test_fake_mutex__double_lock(void) {
  fake_mutex_set_should_assert(false);

  PebbleMutex *mutex = mutex_create();
  mutex_lock(mutex);
  mutex_lock(mutex);
  cl_assert_equal_b(true, fake_mutex_get_assert_triggered());
}

void test_fake_mutex__double_unlock(void) {
  fake_mutex_set_should_assert(false);

  PebbleMutex *mutex = mutex_create();
  mutex_lock(mutex);
  mutex_unlock(mutex);
  mutex_unlock(mutex);
  cl_assert_equal_b(true, fake_mutex_get_assert_triggered());
}

void test_fake_mutex__recursive(void) {
  PebbleRecursiveMutex *mutex = mutex_create_recursive();
  mutex_lock_recursive(mutex);
  mutex_lock_recursive(mutex);
  mutex_lock_recursive(mutex);
  mutex_unlock_recursive(mutex);
  mutex_unlock_recursive(mutex);
  mutex_unlock_recursive(mutex);
  cl_assert_equal_b(fake_mutex_all_unlocked(), true);
}

void test_fake_mutex__recursive_mismatched_counts(void) {
  PebbleRecursiveMutex *mutex = mutex_create_recursive();
  mutex_lock_recursive(mutex);
  mutex_lock_recursive(mutex);
  mutex_unlock_recursive(mutex);
  cl_assert_equal_b(fake_mutex_all_unlocked(), false);
  mutex_unlock_recursive(mutex);
  cl_assert_equal_b(fake_mutex_all_unlocked(), true);
}

void test_fake_mutex__recursive_unlock_nonlocked(void) {
  fake_mutex_set_should_assert(false);

  PebbleRecursiveMutex *mutex = mutex_create_recursive();
  mutex_lock_recursive(mutex);
  mutex_unlock_recursive(mutex);
  mutex_unlock_recursive(mutex);
  fake_mutex_set_should_assert(false);
}

void test_fake_mutex__multiple_mutexes(void) {
  PebbleMutex *mutex_1 = mutex_create();
  PebbleMutex *mutex_2 = mutex_create();

  mutex_lock(mutex_1);
  mutex_lock(mutex_2);
  cl_assert_equal_b(fake_mutex_all_unlocked(), false);
  mutex_unlock(mutex_2);
  cl_assert_equal_b(fake_mutex_all_unlocked(), false);
  mutex_unlock(mutex_1);
  cl_assert_equal_b(fake_mutex_all_unlocked(), true);
}
