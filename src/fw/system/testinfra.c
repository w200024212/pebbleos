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

#include "testinfra.h"

#include "console/pulse_internal.h"
#include "kernel/core_dump.h"
#include "services/common/new_timer/new_timer.h"
#include "system/bootbits.h"
#include "system/logging.h"
#include "system/passert.h"

void notify_system_ready_for_communication(void) {
#if !UNITTEST
  pbl_log(LOG_LEVEL_DEBUG, __FILE_NAME__, __LINE__, "Ready for communication.");
#if PULSE_EVERYWHERE
  static bool s_pulse_started = false;
  if (!s_pulse_started) {
    pulse_start();
    s_pulse_started = true;
  }
#endif
#endif
}

#if IS_BIGBOARD
NORETURN test_infra_quarantine_board(const char *quarantine_reason) {
  PBL_LOG(LOG_LEVEL_INFO, "Quarantine Board: %s", quarantine_reason);
  boot_bit_set(BOOT_BIT_FORCE_PRF);
  core_dump_reset(true /* is_forced */);
}
#endif /* IS_BIGBOARD */
