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

#include "_test/default_only.h"
#include "_test/default_and_custom.h"
#include "_test/custom_only.h"

// Loading of override headers must be done in a separate source file because
// the overrides are not applied to the test harness itself.

int default_only_define(void) {
  return DEFAULT_ONLY_DEFINE;
}

int overridden_define(void) {
  return OVERRIDDEN_DEFINE;
}

int custom_only_define(void) {
  return CUSTOM_ONLY_DEFINE;
}
