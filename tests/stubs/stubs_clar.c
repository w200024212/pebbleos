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

#include <stdbool.h>
#include <setjmp.h>

bool clar_expecting_passert = false;
bool clar_passert_occurred = false;
jmp_buf clar_passert_jmp_buf;

void
clar__assert(
  int condition,
  const char *file,
  int line,
  const char *error_msg,
  const char *description,
  int should_abort)
{};
