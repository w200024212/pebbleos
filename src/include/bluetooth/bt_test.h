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
#include <bluetooth/hci_types.h>

#include <stdbool.h>

void bt_driver_test_start(void);

void bt_driver_test_enter_hci_passthrough(void);

void bt_driver_test_handle_hci_passthrough_character(char c, bool *should_context_switch);

bool bt_driver_test_enter_rf_test_mode(void);

void bt_driver_test_set_spoof_address(const BTDeviceAddress *addr);

void bt_driver_test_stop(void);

bool bt_driver_test_selftest(void);

bool bt_driver_test_mfi_chip_selftest(void);

void bt_driver_le_transmitter_test(
    uint8_t tx_channel, uint8_t tx_packet_length, uint8_t packet_payload);
void bt_driver_le_test_end(void);
void bt_driver_le_receiver_test(uint8_t rx_channel);

typedef void (*BTDriverResponseCallback)(HciStatusCode status, const uint8_t *payload);
void bt_driver_register_response_callback(BTDriverResponseCallback callback);

void bt_driver_start_unmodulated_tx(uint8_t tx_channel);
void bt_driver_stop_unmodulated_tx(void);

typedef enum BtlePaConfig {
  BtlePaConfig_Disable,
  BtlePaConfig_Enable,
  BtlePaConfig_Bypass,
  BtlePaConfigCount
} BtlePaConfig;
void bt_driver_le_test_pa(BtlePaConfig option);

typedef enum BtleCoreDump {
  BtleCoreDump_UserRequest,
  BtleCoreDump_ForceHardFault,
  BtleCoreDump_Watchdog,
  BtleCoreDumpCount
} BtleCoreDump;
void bt_driver_core_dump(BtleCoreDump type);

void bt_driver_send_sleep_test_cmd(bool force_ble_sleep);
