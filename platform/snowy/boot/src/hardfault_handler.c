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

#include "drivers/dbgserial.h"
#include "util/misc.h"
#include "system/die.h"
#include "system/reset.h"

#include "misc.h"
#include "stm32f4xx.h"

#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>

void hard_fault_handler_c(unsigned int* hardfault_args) {
  dbgserial_putstr("HARD FAULT");

#ifdef NO_WATCHDOG
  __BKPT();
  while (1) continue;
#else
  system_hard_reset();
#endif
}

void HardFault_Handler(void) {
  // Grab the stack pointer, shove it into a register and call
  // the c function above.
  __asm("TST LR, #4\n"
        "ITE EQ\n"
        "MRSEQ R0, MSP\n"
        "MRSNE R0, PSP\n"
        "B hard_fault_handler_c\n");
}
