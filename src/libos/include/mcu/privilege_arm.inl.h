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

#define CMSIS_COMPATIBLE
#include <mcu.h>


//! @file privilege_arm.inl.h
//! Helpful functions for dealing with our micros execution state.
//!
//! Functions in this file muck with the control register. This register is described here:
//! http://infocenter.arm.com/help/topic/com.arm.doc.dui0552a/DUI0552A_cortex_m3_dgug.pdf page 2-9
//! We only really care about the 0th bit.
//! [0] nPriv Defines the Thread mode privilege level
//!           0 = Privileged
//!           1 = Unprivileged
//! This variable can be read in both modes, but only may be written in privileged mode.

// See http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0552a/CHDIGFCA.html
// for a more detailed explanation of these various privilege states.

static inline bool mcu_state_is_thread_privileged(void) {
  return (__get_CONTROL() & 0x1) == 0;
}
