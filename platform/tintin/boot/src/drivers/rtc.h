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

//! Initialize the RTC with LSE as the clocksource
//! @return false if LSE init failed
bool rtc_init(void);

//! Set the RTC to run in fast mode
void rtc_initialize_fast_mode(void);

//! Slow down the RTC so we can keep time in standby mode
void rtc_slow_down(void);

//! Speed up the RTC for the firmware
void rtc_speed_up(void);
