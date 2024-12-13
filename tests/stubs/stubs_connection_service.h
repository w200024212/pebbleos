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

#include "applib/connection_service.h"
#include "applib/connection_service_private.h"

bool connection_service_peek_pebble_app_connection(void) {
  return false;
}

bool connection_service_peek_pebblekit_connection(void) {
  return false;
}

void connection_service_unsubscribe(void) {
}

void connection_service_subscribe(ConnectionHandlers conn_handlers) {
}

void connection_service_state_init(ConnectionServiceState *state) {
}

void bluetooth_connection_service_subscribe(ConnectionHandler handler) {
}

void bluetooth_connection_service_unsubscribe(void) {
}

bool bluetooth_connection_service_peek(void) {
  return false;
}
