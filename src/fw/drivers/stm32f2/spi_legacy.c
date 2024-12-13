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

// REVISIT:
// This is a legacy implementation of the prescaler calculation
// code used by the roll-your-own SPI implementations.
// Once the new driver is used for all SPI interaction, this
// function can go away.

#include "system/passert.h"
#include "util/math.h"
#include "board/board.h"

#define STM32F2_COMPATIBLE
#define STM32F4_COMPATIBLE
#define STM32F7_COMPATIBLE
#include <mcu.h>

// Deduced by looking at the prescalers in stm32f2xx_spi.h
#define SPI_FREQ_LOG_TO_PRESCALER(LG) (((LG) - 1) * 0x8)

uint16_t spi_find_prescaler(uint32_t bus_frequency, SpiPeriphClock periph_clock) {
  // Get the clocks
  RCC_ClocksTypeDef clocks;
  RCC_GetClocksFreq(&clocks);

  uint32_t clock = 0;
  // Find which peripheral clock we belong to
  if (periph_clock == SpiPeriphClockAPB1) {
    clock = clocks.PCLK1_Frequency;
  } else if (periph_clock == SpiPeriphClockAPB2) {
    clock = clocks.PCLK2_Frequency;
  } else {
    WTF;
  }

  int lg;
  if (bus_frequency > (clock / 2)) {
    lg = 1; // Underclock to the highest possible frequency
  } else {
    uint32_t divisor = clock / bus_frequency;
    lg = ceil_log_two(divisor);
  }

  // Prescalers only exists for values in [2 - 256] range
  PBL_ASSERTN(lg > 0);
  PBL_ASSERTN(lg < 9);

  // return prescaler
  return (SPI_FREQ_LOG_TO_PRESCALER(lg));
}
