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

#include "mcu/privilege.h"

#include "mcu/interrupts.h"
#include "util/attributes.h"

// These functions need to be called from assembly so they can't be inlined
EXTERNALLY_VISIBLE void mcu_state_set_thread_privilege(bool privileged) {
  uint32_t control = __get_CONTROL();
  if (privileged) {
    control &= ~0x1;
  } else {
    control |= 0x1;
  }
  __set_CONTROL(control);
}

bool mcu_state_is_privileged(void) {
  return mcu_state_is_thread_privileged() || mcu_state_is_isr();
}
