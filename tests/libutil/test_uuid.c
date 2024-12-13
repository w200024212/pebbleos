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

#include "util/uuid.h"
#include "fake_rtc.h"
#include "stubs_passert.h"
#include "stubs_rand_ptr.h"
#include "stubs_pebble_tasks.h"

void test_uuid__equal(void) {
  const Uuid system = UUID_SYSTEM;
  const Uuid invalid = UUID_INVALID;

  cl_assert(uuid_equal(&system, &system));
  cl_assert(uuid_equal(&invalid, &invalid));
  cl_assert(!uuid_equal(&system, &invalid));

  const Uuid test_uuid_1 = (Uuid) {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5
  };

  // Different at the start
  Uuid test_uuid_2 = test_uuid_1;
  ++test_uuid_2.byte0;

  // Different at the end 
  Uuid test_uuid_3 = test_uuid_1;
  ++test_uuid_3.byte15;

  cl_assert(uuid_equal(&test_uuid_1, &test_uuid_1));
  cl_assert(uuid_equal(&test_uuid_2, &test_uuid_2));
  cl_assert(uuid_equal(&test_uuid_3, &test_uuid_3));
  cl_assert(!uuid_equal(&test_uuid_1, &test_uuid_2));
  cl_assert(!uuid_equal(&test_uuid_1, &test_uuid_3));
}

void test_uuid__invalid(void) {
  const Uuid system = UUID_SYSTEM;
  const Uuid invalid = UUID_INVALID;

  const Uuid test_uuid_1 = (Uuid) {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5
  };

  cl_assert(uuid_is_invalid(&invalid));
  cl_assert(!uuid_is_invalid(&system));
  cl_assert(!uuid_is_invalid(&test_uuid_1));
}

void test_uuid__string(void) {
  char buffer[UUID_STRING_BUFFER_LENGTH];

  const Uuid test_uuid_1 = (Uuid) {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5
  };

  uuid_to_string(&test_uuid_1, buffer);
  cl_assert_equal_s(buffer, "{00010203-0405-0607-0809-000102030405}");

  const Uuid system = UUID_SYSTEM;
  uuid_to_string(&system, buffer);
  cl_assert_equal_s(buffer, "{00000000-0000-0000-0000-000000000000}");

  const Uuid invalid = UUID_INVALID;
  uuid_to_string(&invalid, buffer);
  cl_assert_equal_s(buffer, "{ffffffff-ffff-ffff-ffff-ffffffffffff}");

  uuid_to_string(NULL, buffer);
  cl_assert_equal_s(buffer, "{NULL UUID}");
}

