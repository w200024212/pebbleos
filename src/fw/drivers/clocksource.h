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

//! Configure and start the 32 kHz LSE clock.
void clocksource_lse_configure(void);

//! Returns true iff LSE is running.
bool clocksource_is_lse_started(void);

//! Enable or disable 32 kHz clock output on pin MCO1.
//!
//! Prerequisite: clocksource_lse_configure() must be called beforehand to
//! enable the 32 kHz clock.
void clocksource_MCO1_enable(bool on);
