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

#include "drivers/rtc.h"

#include <stdbool.h>
#include <stdint.h>
#include <time.h>

void fake_rtc_init(RtcTicks initial_ticks, time_t initial_time);

void fake_rtc_increment_time(time_t inc);
void fake_rtc_increment_time_ms(uint32_t inc);
void fake_rtc_set_ticks(RtcTicks new_ticks);
void fake_rtc_increment_ticks(RtcTicks tick_increment);
void fake_rtc_auto_increment_ticks(RtcTicks tick_increment);

// TODO: there is a lot of stuff missing.
