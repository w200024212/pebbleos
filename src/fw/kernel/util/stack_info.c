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

#include "FreeRTOS.h"
#include "task.h"

#include "mcu/interrupts.h"

extern uint32_t __isr_stack_start__[];

uint32_t stack_free_bytes(void) {

  // Get the current SP
  register uint32_t SP __asm ("sp");
  uint32_t cur_sp = SP;

  // Default stack
  uint32_t start = (uint32_t) __isr_stack_start__;

  // On ISR stack?
  if (!mcu_state_is_isr()) {
    TaskHandle_t task_handle = xTaskGetCurrentTaskHandle();
    if (task_handle != NULL) {
      // task_handle is NULL before we start the first task
      start = (uint32_t)ulTaskGetStackStart(task_handle);
    }
  }

  return cur_sp - start;
}
