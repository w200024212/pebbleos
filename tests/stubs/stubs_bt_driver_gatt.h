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

#include <bluetooth/gatt.h>
#include "fake_GATTAPI.h"

// TODO: Rethink how we want to stub out these new driver wrapper calls.

void bt_driver_gatt_send_changed_indication(uint32_t connection_id, const ATTHandleRange *data) {
  GATT_Service_Changed_Data_t all_changed_range = {
    .Affected_Start_Handle = data->start,
    .Affected_End_Handle = data->end,
  };
  GATT_Service_Changed_Indication(bt_stack_id(), connection_id, &all_changed_range);
}

void bt_driver_gatt_respond_read_subscription(uint32_t transaction_id, uint16_t response_code) {
  GATT_Service_Changed_CCCD_Read_Response(bt_stack_id(),
                                          transaction_id,
                                          response_code);
}
