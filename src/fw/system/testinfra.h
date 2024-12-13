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

#include <util/attributes.h>

// The automated testing framework shouldn't start operating on the system
// after a reset until PebbleOS is ready to handle requests. This function
// handles that notification
void notify_system_ready_for_communication(void);

#if IS_BIGBOARD
// This sends a notification to infra that we have detected an issue which needs manual
// intervention to debug. Infra should disable the board to give the team time to grab the board and
// investigate.
//
// Note: To preserve the current state, this routine sets the FORCE_PRF boot bit & then
// forces a coredump
NORETURN test_infra_quarantine_board(const char *quarantine_reason);
#endif /* IS_BIGBOARD */
