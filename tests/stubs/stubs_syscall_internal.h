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

#include "kernel/pebble_tasks.h"
#include "system/passert.h"

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

static bool s_syscall_did_fail;

void stubs_syscall_init(void) {
  s_syscall_did_fail = false;
}

NORETURN syscall_failed(void) {
  s_syscall_did_fail = true;
  printf("Warning: Syscall failed!\n");

  // Use cl_assert_passert() if you want to catch this getting hit.
  PBL_ASSERTN(false);
}

#define assert_syscall_failed() \
  cl_assert_equal_b(true, s_syscall_did_fail);

bool syscall_made_from_userspace(void) {
  return true;
}

void syscall_assert_userspace_buffer(const void* buf, size_t num_bytes) {
  if (!buf) {
    syscall_failed();
  }
  // TODO: What else can we check here?
  return;
}

void syscall_init_context() {
}

void syscall_redirect_syscall_exit(PebbleTask task, void (*func)(void)) {
}

void syscall_reset(PebbleTask task) {
}


