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

typedef enum SerialConsoleState {
  SERIAL_CONSOLE_STATE_PROMPT,
  SERIAL_CONSOLE_STATE_LOGGING,
#ifdef UI_DEBUG
  SERIAL_CONSOLE_STATE_LAYER_NUDGING,
#endif
  SERIAL_CONSOLE_STATE_HCI_PASSTHROUGH,
  SERIAL_CONSOLE_STATE_ACCESSORY_PASSTHROUGH,
  SERIAL_CONSOLE_STATE_PROFILER,
  SERIAL_CONSOLE_STATE_PULSE,
  SERIAL_CONSOLE_NUM_STATES
} SerialConsoleState;

// This function cannot be called in a > systick priority IRQ
void serial_console_set_state(SerialConsoleState new_state);

SerialConsoleState serial_console_get_state(void);
