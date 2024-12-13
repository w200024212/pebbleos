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

typedef void (*NewTimerCallback)(void *data);

typedef uint32_t TimerID;

TimerID new_timer_create(void) {
  return 1;
}

bool new_timer_start(TimerID timer, uint32_t timeout_ms, NewTimerCallback cb, void *cb_data,
                     uint32_t flags) {
  return true;
}

bool new_timer_stop(TimerID timer) {
  return true;
}

bool new_timer_scheduled(TimerID timer, uint32_t *expire_ms_p) {
  return true;
}

void new_timer_delete(TimerID timer) {
}

void* new_timer_debug_get_current_callback(void) {
  return NULL;
}
