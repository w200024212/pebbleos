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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <clar.h>

#include "kernel/pebble_tasks.h"
#include "util/rand.h"

// Stubs
///////////////////////////////////////////////////////////
#include "stubs_passert.h"
#include "stubs_rand_ptr.h"

PebbleTask pebble_task_get_current(void) {
  return PebbleTask_KernelMain; // System seed
}

// Tests
///////////////////////////////////////////////////////////

void test_rand__smoke_test(void) {
#define RANDOM_CHECK_LENGTH 512

  uint32_t values[RANDOM_CHECK_LENGTH];
  for(size_t i = 0; i < RANDOM_CHECK_LENGTH; i++) {
    values[i] = rand32();
    for(size_t l = 0; l < i; l++) {
      printf("i,l: %zu,%zu\n", i,l);
      cl_assert(values[i] != values[l]);
    }
  }
}
