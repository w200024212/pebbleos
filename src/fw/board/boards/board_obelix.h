/*
 * Copyright 2025 Core Devices LLC
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

#define BT_VENDOR_ID 0x0EEA
#define BT_VENDOR_NAME "Core Devices LLC"

// Use LXT (requires external crystal mounted)
#define SF32LB52_USE_LXT

extern UARTDevice * const DBG_UART;
extern LCDDevice *const DBG_LCD1;
#ifdef NIMBLE_HCI_SF32LB52_TRACE_BINARY
extern UARTDevice * const HCI_TRACE_UART;
#endif // NIMBLE_HCI_SF32LB52_TRACE_BINARY
extern QSPIPort * const QSPI;
extern QSPIFlash * const QSPI_FLASH;
extern I2CBus *const I2C1_BUS;
extern const BoardConfigPower BOARD_CONFIG_POWER;
extern const BoardConfig BOARD_CONFIG;
