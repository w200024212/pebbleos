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

bool comm_session_has_capability(CommSession *session, CommSessionCapability capability){
  return true;
}

CommSession *comm_session_get_system_session(void) {
  // Don't return NULL, lots of code paths expect a valid session
  return (CommSession *) 1;
}

bool comm_session_is_system(CommSession *session) {
  return false;
}

CommSession *comm_session_get_by_type(CommSessionType type) {
  return NULL;
}

bool comm_session_send_data(CommSession *session, uint16_t endpoint_id,
                            const uint8_t* data, size_t length, uint32_t timeout_ms) {
  return true;
}
