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
#include <stdbool.h>

enum {
  // ML/FL / 1.0 and later:
  OTP_SERIAL1 = 0,
  OTP_HWVER = 1,
  OTP_PCBA_SERIAL1 = 2,
  // Quanta / HW 1.3 and later:
  OTP_SERIAL2 = 3,
  OTP_SERIAL3 = 4,
  OTP_SERIAL4 = 5,
  OTP_SERIAL5 = 6,
  OTP_PCBA_SERIAL2 = 7,
  OTP_PCBA_SERIAL3 = 8,

  NUM_OTP_SLOTS = 16,
};

uint8_t * otp_get_lock(const uint8_t index);
bool otp_is_locked(const uint8_t index);

char * otp_get_slot(const uint8_t index);
