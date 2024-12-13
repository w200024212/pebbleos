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

#include "reboot_reason.h"

#include "mcu/interrupts.h"
#include "os/tick.h"
#include "system/bootbits.h"
#include "system/logging.h"

#define STM32F2_COMPATIBLE
#define STM32F4_COMPATIBLE
#define STM32F7_COMPATIBLE
#include <mcu.h>

#include <inttypes.h>

#include "FreeRTOS.h"
#include "task.h"

_Static_assert(sizeof(RebootReason) == sizeof(uint32_t[6]), "RebootReason is a funny size");

void reboot_reason_set(RebootReason *reason) {
  uint32_t *raw = (uint32_t*)reason;

  if (RTC_ReadBackupRegister(REBOOT_REASON_REGISTER_1)) {
    // It's not safe to log if we're called from an ISR or from a FreeRTOS critical section (basepri != 0)
    if (!mcu_state_is_isr() && __get_BASEPRI() == 0
            && xTaskGetSchedulerState() == taskSCHEDULER_RUNNING) {
      PBL_LOG(LOG_LEVEL_WARNING, "Reboot reason is already set");
    }
    return;
  }

  RTC_WriteBackupRegister(REBOOT_REASON_REGISTER_1, raw[0]);
  RTC_WriteBackupRegister(REBOOT_REASON_REGISTER_2, raw[1]);
  RTC_WriteBackupRegister(REBOOT_REASON_STUCK_TASK_PC, raw[2]);
  RTC_WriteBackupRegister(REBOOT_REASON_STUCK_TASK_LR, raw[3]);
  RTC_WriteBackupRegister(REBOOT_REASON_STUCK_TASK_CALLBACK, raw[4]);
  RTC_WriteBackupRegister(REBOOT_REASON_DROPPED_EVENT, raw[5]);
}

void reboot_reason_set_restarted_safely(void) {
  RebootReason reason;
  reboot_reason_get(&reason);
  reason.restarted_safely = true;

  uint32_t* raw = (uint32_t *)&reason;
  RTC_WriteBackupRegister(REBOOT_REASON_REGISTER_1, *raw);
}

void reboot_reason_get(RebootReason *reason) {
  uint32_t *raw = (uint32_t *)reason;
  raw[0] = RTC_ReadBackupRegister(REBOOT_REASON_REGISTER_1);
  raw[1] = RTC_ReadBackupRegister(REBOOT_REASON_REGISTER_2);
  raw[2] = RTC_ReadBackupRegister(REBOOT_REASON_STUCK_TASK_PC);
  raw[3] = RTC_ReadBackupRegister(REBOOT_REASON_STUCK_TASK_LR);
  raw[4] = RTC_ReadBackupRegister(REBOOT_REASON_STUCK_TASK_CALLBACK);
  raw[5] = RTC_ReadBackupRegister(REBOOT_REASON_DROPPED_EVENT);
}

void reboot_reason_clear(void) {
  RTC_WriteBackupRegister(REBOOT_REASON_REGISTER_1, 0);
  RTC_WriteBackupRegister(REBOOT_REASON_REGISTER_2, 0);
  RTC_WriteBackupRegister(REBOOT_REASON_STUCK_TASK_PC, 0);
  RTC_WriteBackupRegister(REBOOT_REASON_STUCK_TASK_LR, 0);
  RTC_WriteBackupRegister(REBOOT_REASON_STUCK_TASK_CALLBACK, 0);
  RTC_WriteBackupRegister(REBOOT_REASON_DROPPED_EVENT, 0);
}

uint32_t reboot_get_slot_of_last_launched_app(void) {
  return RTC_ReadBackupRegister(SLOT_OF_LAST_LAUNCHED_APP);
}

void reboot_set_slot_of_last_launched_app(uint32_t app_slot) {
  RTC_WriteBackupRegister(SLOT_OF_LAST_LAUNCHED_APP, app_slot);
}

