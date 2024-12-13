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

#include <stdint.h>

typedef struct RTCCalibConfig {
  uint32_t sign;
  uint32_t units;
} RTCCalibConfig;

//! Calculate the appropriate coarse calibration config given the measured and target frequencies
//! (in mHz)
RTCCalibConfig rtc_calibration_get_config(uint32_t frequency, uint32_t target);

void rtc_calibration_init_timer(void);
