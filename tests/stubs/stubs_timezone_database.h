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

#include "services/normal/timezone_database.h"
#include "util/attributes.h"

int WEAK timezone_database_get_region_count(void) {
  return 0;
}

bool WEAK timezone_database_load_region_info(uint16_t region_id, TimezoneInfo *tz_info) {
  return false;
}

bool WEAK timezone_database_load_region_name(uint16_t region_id, char *region_name) {
  return false;
}

bool WEAK timezone_database_load_dst_rule(uint8_t dst_id, TimezoneDSTRule *start,
                                          TimezoneDSTRule *end) {
  return false;
}

int WEAK timezone_database_find_region_by_name(const char *region_name, int region_name_length) {
  return 0;
}
