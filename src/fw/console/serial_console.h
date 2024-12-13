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

void serial_console_init(void);

bool serial_console_is_logging_enabled(void);
bool serial_console_is_prompt_enabled(void);

//! Allow the prompt to be started. By default the prompt is disabled it at system boot, and needs
//! to be enabled once the rest of the system is ready to handle prompt commands.
//! FIXME: This is probably in the wrong place, but we're reworking prompt in general once PULSEv2
//! lands so no need to rearrange the deck chairs on the titanic.
void serial_console_enable_prompt(void);

void serial_console_write_log_message(const char* msg);
