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

#include "stubs_i18n.h"
#include "stubs_fonts.h"
#include "stubs_graphics.h"
#include "stubs_text_node.h"

#include "shell/prefs.h"
#include "services/normal/activity/health_util.h"

UnitsDistance shell_prefs_get_units_distance(void) {
  return UnitsDistance_Miles;
}

void test_health_util__pace(void) {
  cl_assert_equal_i(health_util_get_pace(29, 4800), 10); // PBL-36661
  cl_assert_equal_i(health_util_get_pace(10, 800), 20); // less than a mile
  cl_assert_equal_i(health_util_get_pace(820, 262400), 5); // many miles / long distance
}
