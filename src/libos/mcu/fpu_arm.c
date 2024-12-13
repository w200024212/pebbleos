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

#include "mcu/fpu.h"

#define CMSIS_COMPATIBLE
#include <mcu.h>

#include <stdint.h>

void mcu_fpu_cleanup(void) {
  // The lazy stacking mechanism for the Cortex M4 starts stacking FPU
  // registers during context switches once the thread has used the FPU
  // once. This is problematic because this bumps the stack cost of a context
  // switch by an additional 132 bytes. This routine resets the FPCA bit which
  // controls whether or not this stacking takes place
  // For the Cortex M3, this routine is a no-op

  const uint32_t fpca_bit_mask = 0x4;
  uint32_t control = __get_CONTROL();

  if ((control & fpca_bit_mask) != 0) {
    control &= ~fpca_bit_mask;
    __set_CONTROL(control);
  }
}
