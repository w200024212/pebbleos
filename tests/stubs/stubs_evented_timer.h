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

#include "services/common/evented_timer.h"
#include "util/attributes.h"

void WEAK evented_timer_init(void) {}

void WEAK evented_timer_clear_process_timers(PebbleTask task) {}

EventedTimerID WEAK evented_timer_register(uint32_t timeout_ms, bool repeating,
                                           EventedTimerCallback callback, void* callback_data) {
  return 0;
}

bool WEAK evented_timer_reschedule(EventedTimerID timer, uint32_t new_timeout_ms) {
  return true;
}

EventedTimerID WEAK evented_timer_register_or_reschedule(
    EventedTimerID timer_id, uint32_t timeout_ms, EventedTimerCallback callback, void *data) {
  return 0;
}

void WEAK evented_timer_cancel(EventedTimerID timer) {}

bool WEAK evented_timer_exists(EventedTimerID timer) {
  return true;
}

bool WEAK evented_timer_is_current_task(EventedTimerID timer) {
  return true;
}

void WEAK evented_timer_reset(void) {}
