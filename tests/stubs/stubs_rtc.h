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

#include "util/time/time.h"

void rtc_init(void) {
}

void rtc_init_timers(void) {
}

bool rtc_sanitize_struct_tm(struct tm* t) {
  return false;
}

bool rtc_sanitize_time_t(time_t* t) {
  return false;
}

void rtc_set_time(time_t time) {
}

time_t rtc_get_time(void) {
  return 0;
}

// Wrappers for the above functions that take struct tm instead of time_t
void rtc_set_time_tm(struct tm* time_tm) {
}

void rtc_get_time_tm(struct tm* time_tm) {
}

void rtc_get_time_ms(time_t* out_seconds, uint16_t* out_ms) {
}

void rtc_set_timezone(TimezoneInfo *tzinfo) {
}

void rtc_get_timezone(TimezoneInfo *tzinfo) {
}

uint16_t rtc_get_timezone_id(void) {
  return 0;
}

bool rtc_is_timezone_set(void) {
  return false;
}

// RTC ticks
///////////////////////////////////////////////////////////////////////////////

RtcTicks rtc_get_ticks(void) {
  return 0;
}
