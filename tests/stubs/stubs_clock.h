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

#include "services/common/clock.h"
#include "util/attributes.h"

void WEAK clock_get_since_time(char *buffer, int buf_size, time_t timestamp) {}

void WEAK clock_get_until_time(char *buffer, int buf_size, time_t timestamp,
                               int max_relative_hrs) {}

void WEAK clock_get_until_time_without_fulltime(char *buffer, int buf_size, time_t timestamp,
                                                int max_relative_hrs) {}

void WEAK clock_hour_and_minute_add(int *hour, int *minute, int delta_minutes) {}

size_t WEAK clock_copy_time_string_timestamp(char *buffer, uint8_t size, time_t timestamp) {
  return 0;
}

void WEAK clock_get_friendly_date(char *buffer, int buf_size, time_t timestamp) {}

size_t WEAK clock_get_time_number(char *number_buffer, size_t number_buffer_size,
                                  time_t timestamp) {
  return 0;
}

size_t WEAK clock_get_time_word(char *buffer, size_t buffer_size, time_t timestamp) {
  return 0;
}
