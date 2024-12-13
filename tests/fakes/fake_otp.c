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

#include "fake_otp.h"

#include "drivers/otp.h"
#include "system/passert.h"

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

char s_otp_buffer[512];
uint8_t s_otp_locks[16];

void fake_otp_reset(void) {
  memset(s_otp_buffer, 0xff, sizeof(s_otp_buffer));
  memset(s_otp_locks, 0xff, sizeof(s_otp_locks));
}

char * otp_get_slot(const uint8_t index) {
  PBL_ASSERTN(index < NUM_OTP_SLOTS);
  return (char * const) (s_otp_buffer + (32 * index));
}

uint8_t * otp_get_lock(const uint8_t index) {
  PBL_ASSERTN(index < NUM_OTP_SLOTS);
  return (uint8_t * const) (s_otp_locks + index);
}

bool otp_is_locked(const uint8_t index) {
  return (*otp_get_lock(index) == 0);
}

OtpWriteResult otp_write_slot(const uint8_t index, const char *value) {
  if (otp_is_locked(index)) {
    return OtpWriteFailAlreadyWritten;
  }

  // Write the value
  char *slot = otp_get_slot(index);
  strcpy(slot, value);

  // Lock the OTP sector
  uint8_t *lock = otp_get_lock(index);
  *lock = 0;

  return OtpWriteSuccess;
}
