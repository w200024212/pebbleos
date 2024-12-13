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

#include "util/attributes.h"

#include <stdint.h>
#include <stdbool.h>

typedef enum {
  MsgIdDataTransfer = 0x02,
  MsgIdStopTransfer = 0x03,
} MsgId;

typedef struct PACKED {
  MsgId msg_id;
  AudioEndpointSessionId session_id;
  uint8_t frame_count;
  uint8_t frames[];
} DataTransferMsg;

typedef struct PACKED {
  MsgId msg_id;
  AudioEndpointSessionId session_id;
} StopTransferMsg;
