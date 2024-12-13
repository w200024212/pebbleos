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

#define FILE_LOG_COLOR LOG_COLOR_BLUE

#include "app_launch.h"

#include "comm/ble/gatt_client_operations.h"
#include "services/common/analytics/analytics.h"
#include "services/common/analytics/analytics_event.h"
#include "services/common/comm_session/session.h"
#include "system/logging.h"
#include "system/passert.h"

//! See https://pebbletechnology.atlassian.net/wiki/display/DEV/Pebble+GATT+Services

// -------------------------------------------------------------------------------------------------
// Static variables

static BLECharacteristic s_app_launch_characteristic = BLE_CHARACTERISTIC_INVALID;

// -------------------------------------------------------------------------------------------------

void app_launch_handle_service_discovered(BLECharacteristic *characteristics) {
  PBL_ASSERTN(characteristics);

  if (s_app_launch_characteristic != BLE_CHARACTERISTIC_INVALID) {
    PBL_LOG(LOG_LEVEL_WARNING, "Multiple app launch services!? Will use most recent one.");
  }

  s_app_launch_characteristic = *characteristics;

  // If there was no system session, try launching the Pebble app:
  if (!comm_session_get_system_session()) {
    app_launch_trigger();
  }
}

void app_launch_invalidate_all_references(void) {
  s_app_launch_characteristic = BLE_CHARACTERISTIC_INVALID;
}

void app_launch_handle_service_removed(
    BLECharacteristic *characteristics, uint8_t num_characteristics) {
  app_launch_invalidate_all_references();
}

// -------------------------------------------------------------------------------------------------

bool app_launch_can_handle_characteristic(BLECharacteristic characteristic) {
  return (characteristic == s_app_launch_characteristic);
}

// -------------------------------------------------------------------------------------------------

void app_launch_handle_read_or_notification(BLECharacteristic characteristic, const uint8_t *value,
                                            size_t value_length, BLEGATTError error) {
  // If error is BLEGATTErrorSuccess, it means the Pebble app responded.
  PBL_LOG(LOG_LEVEL_INFO, "App relaunch result: %u", error);
  if (error == BLEGATTErrorSuccess) {
    analytics_inc(ANALYTICS_DEVICE_METRIC_BT_PEBBLE_APP_LAUNCH_SUCCESS_COUNT,
                  AnalyticsClient_System);
  } else {
    analytics_event_bt_app_launch_error(error);
  }
}

// -------------------------------------------------------------------------------------------------

void app_launch_handle_disconnection(void) {
  s_app_launch_characteristic = BLE_CHARACTERISTIC_INVALID;
}

// -------------------------------------------------------------------------------------------------

void app_launch_trigger(void) {
  if (s_app_launch_characteristic == BLE_CHARACTERISTIC_INVALID) {
    return;
  }
  BTErrno err = gatt_client_op_read(s_app_launch_characteristic, GAPLEClientKernel);
  if (err != BTErrnoOK) {
    PBL_LOG(LOG_LEVEL_ERROR, "App relaunch failed: %u", err);
  }
}
