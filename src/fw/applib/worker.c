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

#include "worker.h"

#include "process_management/worker_manager.h"
#include "process_state/worker_state/worker_state.h"
#include "applib/event_service_client.h"
#include "syscall/syscall.h"
#include "services/common/event_service.h"
#include "system/logging.h"


// -------------------------------------------------------------------------------------------------
static bool prv_handle_event(PebbleEvent* event) {
  PebbleEventType type = event->type;

  switch (type) {
    case PEBBLE_CALLBACK_EVENT:
      event->callback.callback(event->callback.data);
      return true;

    default:
      PBL_LOG_VERBOSE("Received an unhandled event (%u)", event->type);
      return false;
  }
}


// -------------------------------------------------------------------------------------------------
void worker_event_loop(void) {
  // Event loop:
  while (1) {
    PebbleEvent event;

    sys_get_pebble_event(&event);

    if (event.type == PEBBLE_PROCESS_DEINIT_EVENT) {
      // We're done here. Return the app's main function.
      event_cleanup(&event);
      return;
    }

    event_service_client_handle_event(&event);

    prv_handle_event(&event);

    event_cleanup(&event);
  }
}


// -------------------------------------------------------------------------------------------------
void worker_launch_app(void) {
  sys_launch_app_for_worker();
}

