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

#include "drivers/mcu.h"

#define STM32F2_COMPATIBLE
#define STM32F4_COMPATIBLE
#define STM32F7_COMPATIBLE
#include <mcu.h>

#if MICRO_FAMILY_STM32F7
const uint32_t *STM32_UNIQUE_DEVICE_ID_ADDR = (uint32_t*) 0x1ff0f420;
#else
const uint32_t *STM32_UNIQUE_DEVICE_ID_ADDR = (uint32_t*) 0x1fff7a10;
#endif

const uint32_t* mcu_get_serial(void) {
  return STM32_UNIQUE_DEVICE_ID_ADDR;
}

uint32_t mcu_cycles_to_milliseconds(uint64_t cpu_ticks) {
  RCC_ClocksTypeDef clocks;
  RCC_GetClocksFreq(&clocks);
  return ((cpu_ticks * 1000) / clocks.HCLK_Frequency);
}
