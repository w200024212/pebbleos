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

int default_only_define(void);
int overridden_define(void);
int custom_only_define(void);

void test_test_infra__default_override_header(void) {
  // Check that the header in the default override directory was included.
  cl_assert(default_only_define());
}

void test_test_infra__overridden_custom_header(void) {
  // Check that the header in the custom override directory shadowed the default
  // override directory's version.
  cl_assert(overridden_define() == 42);
}

void test_test_infra__custom_only_header(void) {
  // Check that the header only in the custom override directory was included.
  cl_assert(custom_only_define());
}
