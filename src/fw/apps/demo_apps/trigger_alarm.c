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

#include "trigger_alarm.h"

#include "applib/app.h"
#include "process_state/app_state/app_state.h"
#include "applib/ui/app_window_stack.h"
#include "applib/ui/window_stack.h"
#include "kernel/pbl_malloc.h"
#include "kernel/events.h"
#include "drivers/rtc.h"

typedef struct {
  Window window;
} TriggerAlarmData;

static void handle_init(void) {
  TriggerAlarmData *data = app_malloc_check(sizeof(TriggerAlarmData));

  app_state_set_user_data(data);
  window_init(&data->window, WINDOW_NAME("Trigger Alarm Demo"));
  const bool animated = true;
  app_window_stack_push(&data->window, animated);

  PebbleEvent e = (PebbleEvent) {
    .type = PEBBLE_ALARM_CLOCK_EVENT,
    .alarm_clock = {
      .alarm_time = rtc_get_time(),
      .alarm_label = "Wake Up"
    }
  };

  event_put(&e);
}

static void handle_deinit(void) {
  TriggerAlarmData *data = (TriggerAlarmData*)app_state_get_user_data();
  app_free(data);
}

static void s_main(void) {
  handle_init();

  app_event_loop();

  handle_deinit();
}

const PebbleProcessMd* trigger_alarm_get_app_info() {
  static const PebbleProcessMdSystem s_trigger_alarm = {
    .common.main_func = s_main,
    .name = "Trigger Alarm"
  };

  return (const PebbleProcessMd*) &s_trigger_alarm;
}

