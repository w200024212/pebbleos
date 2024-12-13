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

#include "services/common/regular_timer.h"

void regular_timer_init(void) { }

void regular_timer_add_seconds_callback(RegularTimerInfo* cb) { }

void regular_timer_add_multisecond_callback(RegularTimerInfo* cb, uint16_t seconds) { }

void regular_timer_add_minutes_callback(RegularTimerInfo* cb) { }

void regular_timer_add_multiminute_callback(RegularTimerInfo* cb, uint16_t minutes) { }

bool regular_timer_remove_callback(RegularTimerInfo* cb) {
  return true;
}

bool regular_timer_is_scheduled(RegularTimerInfo *cb) {
  return true;
}
