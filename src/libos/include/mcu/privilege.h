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

#pragma once

#include <stdbool.h>

inline static bool mcu_state_is_thread_privileged(void);

//! Update the thread mode privilege bit in the control register. Note that you
//! must already be privileged to call this with a true argument.
void mcu_state_set_thread_privilege(bool privilege);

bool mcu_state_is_privileged(void);

#ifdef __arm__
#include "mcu/privilege_arm.inl.h"
#else
#include "mcu/privilege_stubs.inl.h"
#endif
