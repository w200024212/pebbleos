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

#include "die.h"
#include "drivers/dbgserial.h"
#include "system/reset.h"
#include "system/passert.h"

NORETURN reset_due_to_software_failure(void) {
#if defined(NO_WATCHDOG)
  // Don't reset right away, leave it in a state we can inspect

  while (1) {
    BREAKPOINT;
  }
#endif

  dbgserial_putstr("Software failure; resetting!");
  system_reset();
}
