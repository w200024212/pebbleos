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

//! Auto-shutdown when idle in PRF to increase the changes of getting Pebbles shipped
//! that have some level of battery charge in them.

//! Start listening for battery connection, bluetooth connection, and button events to feed a
//! watchdog.
void prf_idle_watchdog_start(void);

//! Stop the watchdog. We will no longer reset if events don't occur frequently enough.
void prf_idle_watchdog_stop(void);
