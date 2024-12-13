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

#include "services/normal/notifications/ancs/ancs_notifications_util.h"

// Stubs
////////////////////////////////////////////////////////////////
#include "stubs_logging.h"
#include "stubs_passert.h"
#include "stubs_pbl_malloc.h"

// Fakes
////////////////////////////////////////////////////////////////
#include "fakes/fake_rtc.h"

// Tests
////////////////////////////////////////////////////////////////
void test_ancs_notifications_util__initialize(void) {
}

void test_ancs_notifications_util__cleanup(void) {
}

static ANCSAttribute *prv_create_ancs_attr(const char *str) {
  const size_t len = strlen(str);
  ANCSAttribute *attr = malloc(sizeof(ANCSAttribute) + len);
  attr->length = len;
  memcpy(&attr->value, str, len);
  return attr;
}

static void prv_destroy_ancs_attr(ANCSAttribute *attr) {
  free(attr);
}

void test_ancs_notifications_util__parse_timestamp(void) {
  struct tm apr_3_13_00 = {
    .tm_sec = 0,
    .tm_min = 0,
    .tm_hour = 13,
    .tm_mday = 3,
    .tm_mon = 3, // Apr
    .tm_year = 2015 - 1900,
    .tm_isdst = 1,
  };

  // DST info for US/Canada 2015
  TimezoneInfo tz_info = {
    .dst_start = 1425780000, // Sun, 08 Mar 2015 02:00
    .dst_end = 1446343200 // Sun, 01 Nov 2015 02:00
  };
  time_util_update_timezone(&tz_info);

  time_t actual = mktime(&apr_3_13_00);
  rtc_set_time(actual);

  ANCSAttribute *valid_date = prv_create_ancs_attr("20150403T130000");
  time_t calculated = ancs_notifications_util_parse_timestamp(valid_date);
  prv_destroy_ancs_attr(valid_date);
  cl_assert_equal_i(calculated, actual);

  ANCSAttribute *invalid_date = prv_create_ancs_attr("b4150403T123456");
  calculated = ancs_notifications_util_parse_timestamp(invalid_date);
  prv_destroy_ancs_attr(invalid_date);
  cl_assert_equal_i(calculated, 0);

  ANCSAttribute *crazy_bad_date = prv_create_ancs_attr("F");
  calculated = ancs_notifications_util_parse_timestamp(crazy_bad_date);
  prv_destroy_ancs_attr(crazy_bad_date);
  cl_assert_equal_i(calculated, 0);

  ANCSAttribute *zero_length_date = prv_create_ancs_attr("");
  calculated = ancs_notifications_util_parse_timestamp(zero_length_date);
  prv_destroy_ancs_attr(zero_length_date);
  cl_assert_equal_i(calculated, 0);
}
