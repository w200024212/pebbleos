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

#include "system/reset.h"

#include "drivers/display.h"

#include "stm32f7xx.h"

void system_reset(void) {
  display_prepare_for_reset();

  // Clear the reset reason since it will no longer
  // apply after this bootloader reset
  RCC_ClearFlag();

  system_hard_reset();
}

void system_hard_reset(void) {
  NVIC_SystemReset();
  __builtin_unreachable();
}
