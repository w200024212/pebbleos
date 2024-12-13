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

#include "util/time/time.h"

#define BLE_HRM_REMINDER_POPUP_DELAY_MINS (2 * MINUTES_PER_HOUR)

typedef struct GAPLEConnection GAPLEConnection;

typedef struct BLEHRMSharingRequest BLEHRMSharingRequest;

//! Called by the ble_hrm_sharing_popup upon the user's action to grant or decline the sharing.
//! @note Also cleans up the sharing_request object.
void ble_hrm_handle_sharing_request_response(bool is_granted,
                                             BLEHRMSharingRequest *sharing_request);

bool ble_hrm_is_supported_and_enabled(void);

bool ble_hrm_is_sharing_to_connection(const GAPLEConnection *connection);

bool ble_hrm_is_sharing(void);

void ble_hrm_revoke_sharing_permission_for_connection(GAPLEConnection *connection);

void ble_hrm_revoke_all(void);

void ble_hrm_handle_activity_prefs_heart_rate_is_enabled(bool is_enabled);

void ble_hrm_handle_disconnection(GAPLEConnection *connection);

void ble_hrm_init(void);

void ble_hrm_deinit(void);
