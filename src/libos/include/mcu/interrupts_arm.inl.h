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

#define CMSIS_COMPATIBLE
#include <mcu.h>

static inline bool mcu_state_is_isr(void) {
  return __get_IPSR() != 0;
}

static inline uint32_t mcu_state_get_isr_priority(void) {
  uint32_t exc_number  = __get_IPSR();
  if (exc_number == 0) {
    return ~0;
  }
  // Exception numbers 0 -> 15 are "internal" interrupts and NVIC_GetPriority() expects them to be
  // negative numbers.
  return NVIC_GetPriority((int)exc_number - 16);
}
