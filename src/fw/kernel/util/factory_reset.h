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

//! Factory resets the device by wiping the flash
//! @param should_shutdown If true, shutdown after factory resetting, otherwise reboot.
void factory_reset(bool should_shutdown);

//! Factory resets the device by deleting all files
void factory_reset_fast(void *unused);

//! Returns true if a factory reset is in progress.
bool factory_reset_ongoing(void);
