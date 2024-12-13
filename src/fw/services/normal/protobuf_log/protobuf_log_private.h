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

#include "pb.h"
#include "pb_decode.h"
#include "pb_encode.h"

#include "protobuf_log.h"

#include "util/attributes.h"

#include <stdint.h>

// This fixed size header is placed at the beginning of the buffer, before the protobuf
// encoded message
typedef struct PACKED {
  uint16_t msg_size;
} PLogMessageHdr;

// Internal structure of a protobuf log session
typedef struct PLogSession {
  // TODO Change comments from MeasurementSet to MeasurementSet/Events

  ProtobufLogConfig config;
  uint8_t *msg_buffer;      // allocated buffer for the final record: PLogMessageHdr + Payload
  uint8_t *data_buffer;     // allocated buffer for the encoded data blob. (e.g. MeasurementSet)
                            // We form the MeasurementSet first, and then after it's complete we
                            // copy it into msg_buffer inside of a Payload
  size_t max_msg_size;      // max # of bytes to use in the allocated buffer
  size_t max_data_size;     // max allowed size of the encoded data blob
  pb_ostream_t data_stream; // output stream we are writing the data blob to
  time_t start_utc;         // UTC time when session was created
  ProtobufLogTransportCB transport;
} PLogSession;
