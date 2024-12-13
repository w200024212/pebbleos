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

#include <stdint.h>

typedef struct CommSession CommSession;

typedef enum {
  CommSessionCloseReason_UnderlyingDisconnection = 0,
  CommSessionCloseReason_ClosedRemotely = 1,
  CommSessionCloseReason_ClosedLocally = 2,
  CommSessionCloseReason_TransportSpecificBegin = 100,
  CommSessionCloseReason_TransportSpecificEnd = 255,
} CommSessionCloseReason;

typedef enum {
  CommSessionTransportType_PlainSPP = 0,
  CommSessionTransportType_iAP = 1,
  CommSessionTransportType_PPoGATT = 2,
  CommSessionTransportType_QEMU = 3,
  CommSessionTransportType_PULSE = 4,
} CommSessionTransportType;

//! Assumes bt_lock() is held by the caller.
CommSessionTransportType comm_session_analytics_get_transport_type(CommSession *session);

void comm_session_analytics_open_session(CommSession *session);

void comm_session_analytics_close_session(CommSession *session, CommSessionCloseReason reason);

void comm_session_analytics_inc_bytes_sent(CommSession *session, uint16_t length);

void comm_session_analytics_inc_bytes_received(CommSession *session, uint16_t length);
