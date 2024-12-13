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

#include "clar_asserts.h"

#include "applib/event_service_client.h"
#include "fake_events.h"

static EventServiceInfo s_event_handler[PEBBLE_NUM_EVENTS];

void event_service_client_subscribe(EventServiceInfo *service_info) {
  cl_assert_equal_p(s_event_handler[service_info->type].handler, NULL);
  s_event_handler[service_info->type] = *service_info;
}

void event_service_client_unsubscribe(EventServiceInfo *service_info) {
  s_event_handler[service_info->type] = (EventServiceInfo) {};
}

void fake_event_service_init(void) {
  memset(s_event_handler, sizeof(s_event_handler), 0);
}

void fake_event_service_handle_last(void) {
  PebbleEvent event = fake_event_get_last();
  EventServiceInfo *service_info = &s_event_handler[event.type];
  cl_assert(service_info->handler);
  service_info->handler(&event, service_info->context);
}

EventServiceInfo *fake_event_service_get_info(PebbleEventType type) {
  return &s_event_handler[type];
}

