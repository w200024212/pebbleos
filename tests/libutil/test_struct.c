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

#include "util/struct.h"

typedef struct NullSafeFieldAccessTestStruct {
  int field_to_access;
  int *ptr_field_to_access;
} NullSafeFieldAccessTestStruct;

void test_struct__null_safe_access_field(void) {
  // Passing in NULL for the struct ptr should return the default value
  // (supporting both pointer and non-pointer types)
  NullSafeFieldAccessTestStruct *null_ptr = NULL;
  cl_assert_equal_i(NULL_SAFE_FIELD_ACCESS(null_ptr, field_to_access, 1234), 1234);
  cl_assert_equal_p(NULL_SAFE_FIELD_ACCESS(null_ptr, ptr_field_to_access, NULL), NULL);

  int data = 1337;
  const NullSafeFieldAccessTestStruct test_struct = (NullSafeFieldAccessTestStruct) {
    .field_to_access = data,
    .ptr_field_to_access = &data,
  };

  // Passing in a valid struct ptr should return the field
  // (supporting both pointer and non-pointer types)
  const int result = NULL_SAFE_FIELD_ACCESS(&test_struct, field_to_access, 1234);
  cl_assert_equal_i(result, test_struct.field_to_access);
  const int *ptr_result = NULL_SAFE_FIELD_ACCESS(&test_struct, ptr_field_to_access, NULL);
  cl_assert_equal_p(ptr_result, test_struct.ptr_field_to_access);
}
