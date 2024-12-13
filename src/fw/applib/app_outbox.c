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

#include "applib/app_outbox.h"
#include "kernel/events.h"
#include "process_state/app_state/app_state.h"
#include "syscall/syscall.h"

static void prv_handle_event(PebbleEvent *e, void *unused) {
  const PebbleAppOutboxSentEvent *sent_event = &e->app_outbox_sent;
  sent_event->sent_handler(sent_event->status, sent_event->cb_ctx);
}

void app_outbox_send(const uint8_t *data, size_t length,
                     AppOutboxSentHandler sent_handler, void *cb_ctx) {
  sys_app_outbox_send(data, length, sent_handler, cb_ctx);
}

void app_outbox_init(void) {
  EventServiceInfo *info = app_state_get_app_outbox_subscription_info();
  *info = (EventServiceInfo) {
    .type = PEBBLE_APP_OUTBOX_SENT_EVENT,
    .handler = prv_handle_event,
  };
  event_service_client_subscribe(info);
}
