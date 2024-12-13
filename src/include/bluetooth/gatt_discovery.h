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

#include <bluetooth/bluetooth_types.h>
#include <bluetooth/gatt_service_types.h>
#include <util/attributes.h>

#include <stdint.h>

typedef struct GAPLEConnection GAPLEConnection;
typedef struct GATTService GATTService;
typedef struct GATTServiceNode GATTServiceNode;

BTErrno bt_driver_gatt_start_discovery_range(
    const GAPLEConnection *connection, const ATTHandleRange *data);
BTErrno bt_driver_gatt_stop_discovery(GAPLEConnection *connection);

//! It's possible we are disconnected or the stack gets torn down while in the
//! middle of a discovery. This routine gets invoked if the connection gets
//! torn down or goes away so that the implementation can clean up any tracking
//! it has waiting for a discovery to complete
void bt_driver_gatt_handle_discovery_abandoned(void);

//! gatt_service_discovery callbacks
//! cb returns true iff the driver completed, false if a discovery retry was initiated
extern bool bt_driver_cb_gatt_client_discovery_complete(GAPLEConnection *connection, BTErrno errno);
extern void bt_driver_cb_gatt_client_discovery_handle_indication(
    GAPLEConnection *connection, GATTService *service_discovered, BTErrno error);
