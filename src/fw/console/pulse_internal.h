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
#include <stdint.h>

#define PULSE_KEEPALIVE_TIMEOUT_DECISECONDS (30)
#if PULSE_EVERYWHERE
#define PULSE_MAX_RECEIVE_UNIT (1500)
#define PULSE_MIN_FRAME_LENGTH (6)
#else
#define PULSE_MAX_RECEIVE_UNIT (520)
#define PULSE_MIN_FRAME_LENGTH (5)
#endif

//! Start a PULSE session on dbgserial.
void pulse_start(void);

//! End a PULSE session on dbgserial.
void pulse_end(void);

//! Terminate the PULSE session in preparation for the firmware to crash.
void pulse_prepare_to_crash(void);

//! PULSE ISR receive character handler.
void pulse_handle_character(char c, bool *should_context_switch);

//! Change the dbgserial baud rate.
void pulse_change_baud_rate(uint32_t new_baud);
