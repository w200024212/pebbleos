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

#include "services/normal/activity/hr_util.h"

#include "stubs_activity.h"

void test_hr_util__initialize(void) {

}

void test_hr_util__cleanup(void) {

}

// ---------------------------------------------------------------------------------------
void test_hr_util__get_hr_zone(void) {
  // Test some BPM values below the min_hr
  cl_assert_equal_i(hr_util_get_hr_zone(20),  HRZone_Zone0);
  cl_assert_equal_i(hr_util_get_hr_zone(40),  HRZone_Zone0);
  cl_assert_equal_i(hr_util_get_hr_zone(60),  HRZone_Zone0);

  // Test some valid BPM values
  cl_assert_equal_i(hr_util_get_hr_zone(80),  HRZone_Zone0);
  cl_assert_equal_i(hr_util_get_hr_zone(100), HRZone_Zone0);
  cl_assert_equal_i(hr_util_get_hr_zone(120), HRZone_Zone0);
  cl_assert_equal_i(hr_util_get_hr_zone(140), HRZone_Zone1);
  cl_assert_equal_i(hr_util_get_hr_zone(160), HRZone_Zone2);
  cl_assert_equal_i(hr_util_get_hr_zone(180), HRZone_Zone3);

  // Test some BPM values above the max_hr
  cl_assert_equal_i(hr_util_get_hr_zone(200), HRZone_Zone3);
  cl_assert_equal_i(hr_util_get_hr_zone(220), HRZone_Zone3);
  cl_assert_equal_i(hr_util_get_hr_zone(240), HRZone_Zone3);
}

void test_hr_util__is_elevated(void) {
  cl_assert_equal_b(hr_util_is_elevated(60), false);
  cl_assert_equal_b(hr_util_is_elevated(80), false);
  cl_assert_equal_b(hr_util_is_elevated(99), false);

  cl_assert_equal_b(hr_util_is_elevated(100), true);
  cl_assert_equal_b(hr_util_is_elevated(120), true);
  cl_assert_equal_b(hr_util_is_elevated(240), true);
}
