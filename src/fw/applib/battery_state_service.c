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

#include "battery_state_service.h"

#include "event_service_client.h"
#include "kernel/events.h"
#include "services/common/event_service.h"
#include "syscall/syscall.h"
#include "system/passert.h"

#include "process_state/app_state/app_state.h"
#include "process_state/worker_state/worker_state.h"


// ----------------------------------------------------------------------------------------------------
static BatteryStateServiceState* prv_get_state(PebbleTask task) {
  if (task == PebbleTask_Unknown) {
    task = pebble_task_get_current();
  }

  if (task == PebbleTask_App) {
    return app_state_get_battery_state_service_state();
  } else if (task == PebbleTask_Worker) {
    return worker_state_get_battery_state_service_state();
  } else {
    WTF;
  }
}


static void do_handle(PebbleEvent *e, void *context) {
  BatteryStateServiceState *state = prv_get_state(PebbleTask_Unknown);
  PBL_ASSERTN(state->handler != NULL);
  state->handler(sys_battery_get_charge_state());
}

void battery_state_service_init(void) {
  event_service_init(PEBBLE_BATTERY_STATE_CHANGE_EVENT, NULL, NULL);
}

void battery_state_service_subscribe(BatteryStateHandler handler) {
  BatteryStateServiceState *state = prv_get_state(PebbleTask_Unknown);
  state->handler = handler;
  event_service_client_subscribe(&state->bss_info);
}

BatteryChargeState battery_state_service_peek(void) {
  return (sys_battery_get_charge_state());
}

void battery_state_service_unsubscribe(void) {
  BatteryStateServiceState *state = prv_get_state(PebbleTask_Unknown);
  event_service_client_unsubscribe(&state->bss_info);
  state->handler = NULL;
}

void battery_state_service_state_init(BatteryStateServiceState *state) {
  *state = (BatteryStateServiceState) {
    .bss_info = {
      .type = PEBBLE_BATTERY_STATE_CHANGE_EVENT,
      .handler = &do_handle,
    },
  };
}
