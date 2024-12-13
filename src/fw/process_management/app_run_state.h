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

#include "services/common/comm_session/session.h"
#include "util/uuid.h"

typedef enum {
  //! Used as reply from the watch to the phone, to indicate the app is running.
  //! Or, when pushed from phone to watch, this value will have the effect of launching the app.
  RUNNING = 0x01,
  //! Used as reply from the watch to the phone, to indicate the app is not running.
  //! Or, when pushed from phone to watch, this value will have the effect of killing the app.
  NOT_RUNNING = 0x02
} AppState;

typedef enum {
  //! These keys (with accompanying UUID values self FETCH) can be pushed from the phone to
  //! the watch to launch/kill an app on the watch or query which application is running.
  //! Backwards compatible for support of deprecated 0x31
  APP_RUN_STATE_INVALID_COMMAND = 0x00, // Invalid state key, used as a default value
  APP_RUN_STATE_RUN_COMMAND = 0x01,   // Watch -> Phone: App is running, Phone -> Watch: Start app
  APP_RUN_STATE_STOP_COMMAND = 0x02,  // Watch -> Phone: App is stopped, Phone -> Watch: Stop app
  APP_RUN_STATE_STATUS_COMMAND = 0x03 // Phone -> Watch: Request current app UUID
} AppRunStateCommand;

void app_run_state_send_update(const Uuid *uuid, AppState app_state);

// Currently only needed for backwards support of the 0x32 endpoint, at which point
// it will become static and not exported.
void app_run_state_command(CommSession *session, AppRunStateCommand cmd, const Uuid *uuid);
