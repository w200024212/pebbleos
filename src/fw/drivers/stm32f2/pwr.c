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

#include "drivers/pwr.h"

#include "drivers/periph_config.h"

#define STM32F2_COMPATIBLE
#include <mcu.h>

void pwr_enable_wakeup(bool enable) {
  PWR_WakeUpPinCmd(enable ? ENABLE : DISABLE);
}

void pwr_flash_power_down_stop_mode(bool power_down) {
  PWR_FlashPowerDownCmd(power_down ? ENABLE : DISABLE);
}

void pwr_access_backup_domain(bool enable_access) {
  periph_config_enable(PWR, RCC_APB1Periph_PWR);
  PWR_BackupAccessCmd(enable_access ? ENABLE : DISABLE);
  periph_config_disable(PWR, RCC_APB1Periph_PWR);
}
