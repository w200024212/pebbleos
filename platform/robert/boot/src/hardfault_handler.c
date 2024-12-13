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
#include "system/die.h"
#include "system/reset.h"

static void prv_hard_fault_handler_c(unsigned int *hardfault_args) {
  dbgserial_putstr("HARD FAULT");

#ifdef NO_WATCHDOG
  reset_due_to_software_failure();
#else
  system_hard_reset();
#endif
}

void HardFault_Handler(void) {
  // Grab the stack pointer, shove it into a register and call
  // the c function above.
  __asm("tst lr, #4\n"
        "ite eq\n"
        "mrseq r0, msp\n"
        "mrsne r0, psp\n"
        "b %0\n" :: "i" (prv_hard_fault_handler_c));
}
