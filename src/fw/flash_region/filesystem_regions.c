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

#include "flash_region/filesystem_regions.h"

#include "util/size.h"

void filesystem_regions_erase_all(void) {
  for (unsigned int i = 0; i < ARRAY_LENGTH(s_region_list); i++) {
    flash_region_erase_optimal_range_no_watchdog(s_region_list[i].start, s_region_list[i].start,
                                                 s_region_list[i].end, s_region_list[i].end);
  }
}
