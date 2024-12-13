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

#include "ble_app_support.h"

#include "comm/ble/gap_le_scan.h"
#include "comm/ble/gap_le_connect.h"
#include "comm/ble/gatt_client_operations.h"
#include "comm/ble/gatt_client_subscriptions.h"

#include "process_state/app_state/app_state.h"

//! @see ble_scan.c
extern void ble_scan_handle_event(PebbleEvent *e, void *context);

//! @see ble_central.c
extern void ble_central_handle_event(PebbleEvent *e, void *context);

//! @see ble_client.c
extern void ble_client_handle_event(PebbleEvent *e, void *context);

void ble_init_app_state(void) {
  BLEAppState *ble_app_state = app_state_get_ble_app_state();
  *ble_app_state = (const BLEAppState) {
    // ble_scan_...:
    .scan_service_info = (const EventServiceInfo) {
      .type = PEBBLE_BLE_SCAN_EVENT,
      .handler = ble_scan_handle_event,
    },

    // ble_central_...:
    .connection_service_info = (const EventServiceInfo) {
      .type = PEBBLE_BLE_CONNECTION_EVENT,
      .handler = ble_central_handle_event,
    },

    // ble_client_...:
    .gatt_client_service_info = (const EventServiceInfo) {
      .type = PEBBLE_BLE_GATT_CLIENT_EVENT,
      .handler = ble_client_handle_event,
    },
  };
}

void ble_app_cleanup(void) {
  // Gets run on the KernelMain task.
  // All kernel / shared resources for BLE that were allocated on behalf of the
  // app must be freed / released here:
  gap_le_stop_scan();
  gap_le_connect_cancel_all(GAPLEClientApp);
  gatt_client_subscriptions_cleanup_by_client(GAPLEClientApp);
  gatt_client_op_cleanup(GAPLEClientApp);
}
