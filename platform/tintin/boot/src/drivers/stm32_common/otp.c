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

#include "drivers/otp.h"

#include "stm32f2xx_flash.h"

#include <stdint.h>
#include <stdbool.h>

// See page 53 of STM Reference Manual RM0033:
#define OTP_SLOTS_BASE_ADDR (0x1FFF7800)
#define OTP_LOCKS_BASE_ADDR (0x1FFF7A00)

//! Each OTP slot is 32 bytes. There are 16 slots: [0-15]
char * otp_get_slot(const uint8_t index) {
  return (char * const) (OTP_SLOTS_BASE_ADDR + (32 * index));
}

uint8_t * otp_get_lock(const uint8_t index) {
  return (uint8_t * const) (OTP_LOCKS_BASE_ADDR + index);
}

bool otp_is_locked(const uint8_t index) {
  return (*otp_get_lock(index) == 0);
}
