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

#include "drivers/system_flash.h"

#define STM32F2_COMPATIBLE
#define STM32F4_COMPATIBLE
#define STM32F7_COMPATIBLE
#include <mcu.h>

#include "system/logging.h"

void system_flash_erase(uint16_t sector) {
  PBL_LOG_VERBOSE("system_flash_erase");

  FLASH_Unlock();
  FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                  FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);

  if (FLASH_EraseSector(sector, VoltageRange_1) != FLASH_COMPLETE) {
    PBL_LOG(LOG_LEVEL_ALWAYS, "failed to erase sector %u", sector);
    return;
  }
}

void system_flash_write_byte(uint32_t address, uint8_t data) {
  FLASH_Unlock();
  FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                  FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);

  if (FLASH_ProgramByte(address, data) != FLASH_COMPLETE) {
    PBL_LOG(LOG_LEVEL_DEBUG, "failed to write address %p", (void*) address);
    return;
  }
}

uint32_t system_flash_read(uint32_t address) {
  uint32_t data = *(volatile uint32_t*) address;
  return data;
}
