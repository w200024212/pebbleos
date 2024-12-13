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

#include "util/uuid.h"
#include "services/common/analytics/analytics_event.h"
#include "services/common/comm_session/session_internal.h"

//! Stub for PRF

void analytics_event_crash(uint8_t crash_code, uint32_t link_register) {
}

void analytics_event_local_bt_disconnect(uint16_t handle, uint32_t lr) {
}

typedef struct CommSession CommSession;
void analytics_event_put_byte_stats(
    CommSession *session, bool crc_good, uint8_t type,
    uint32_t bytes_transferred, uint32_t elapsed_time_ms,
    uint32_t conn_events, uint32_t sync_errors, uint32_t skip_errors, uint32_t other_errors) {
}

void analytics_event_PPoGATT_disconnect(time_t timestamp, bool successful_reconnect) {
}

void analytics_event_get_bytes_stats(
  CommSession *session, uint8_t type, uint32_t bytes_transferred, uint32_t elapsed_time_ms,
  uint32_t conn_events, uint32_t sync_errors, uint32_t skip_errors, uint32_t other_errors) {
}
