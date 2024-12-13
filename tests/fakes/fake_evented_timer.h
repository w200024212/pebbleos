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

#include <stdbool.h>

#include "services/common/evented_timer.h"

typedef struct {
  uint32_t timeout_ms;
  EventedTimerCallback callback;
  void *callback_data;
  bool repeating;
} FakeEventedTimer;

EventedTimerID evented_timer_register(uint32_t timeout_ms, bool repeating,
                                      EventedTimerCallback callback, void* callback_data) {
  FakeEventedTimer *fake_timer = malloc(sizeof(FakeEventedTimer));
  fake_timer->timeout_ms = timeout_ms;
  fake_timer->callback = callback;
  fake_timer->callback_data = callback_data;
  fake_timer->repeating = repeating;
  return (EventedTimerID)fake_timer;
}


bool evented_timer_reschedule(EventedTimerID timer_id, uint32_t new_timeout_ms) {
  if (timer_id) {
    FakeEventedTimer *fake_timer = (FakeEventedTimer*)timer_id;
    fake_timer->timeout_ms = new_timeout_ms;
    return true;
  }
  return false;
}

EventedTimerID evented_timer_register_or_reschedule(EventedTimerID timer_id, uint32_t timeout_ms,
    EventedTimerCallback callback, void *data) {
  if (timer_id && evented_timer_reschedule(timer_id, timeout_ms)) {
    return timer_id;
  } else {
    return evented_timer_register(timeout_ms, false, callback, data);
  }
}

void evented_timer_cancel(EventedTimerID timer_id) {
  if (timer_id) {
    FakeEventedTimer *fake_timer = (FakeEventedTimer*)timer_id;
    free(fake_timer);
  }
}

bool fake_evented_timer_trigger(EventedTimerID timer_id) {
  if (timer_id) {
    FakeEventedTimer *fake_timer = (FakeEventedTimer*)timer_id;
    fake_timer->callback(fake_timer->callback_data);
    if (!fake_timer->repeating) {
      free(fake_timer);
    }
    return true;
  }
  return false;
}

