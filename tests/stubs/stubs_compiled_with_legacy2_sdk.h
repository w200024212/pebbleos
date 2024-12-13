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

static bool s_is_legacy2 = false;

void process_manager_set_compiled_with_legacy2_sdk(bool is_legacy2) {
  s_is_legacy2 = is_legacy2;
}

bool process_manager_compiled_with_legacy2_sdk(void) {
#if LEGACY2_TEST
  return true;
#else
  return s_is_legacy2;
#endif
}

