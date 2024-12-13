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

#include "stm32f7xx.h"

void pwr_access_backup_domain(bool enable_access) {
  periph_config_enable(PWR, RCC_APB1Periph_PWR);
  if (enable_access) {
    __atomic_or_fetch(&PWR->CR1, PWR_CR1_DBP, __ATOMIC_RELAXED);
  } else {
    __atomic_and_fetch(&PWR->CR1, ~PWR_CR1_DBP, __ATOMIC_RELAXED);
  }
  periph_config_disable(PWR, RCC_APB1Periph_PWR);
}


bool pwr_did_boot_from_standby(void) {
  bool result = (PWR->CSR1 & PWR_CSR1_SBF) != 0;
  return result;
}

void pwr_clear_boot_from_standby_flag(void) {
  PWR->CR1 |= PWR_CR1_CSBF;
}
