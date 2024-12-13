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
#include <stdbool.h>

static const uint8_t HDLC_FLAG = 0x7E;
static const uint8_t HDLC_ESCAPE = 0x7D;
static const uint8_t HDLC_ESCAPE_MASK = 0x20;

typedef struct {
  bool escape;
} HdlcStreamingContext;

void hdlc_streaming_decode_reset(HdlcStreamingContext *ctx);
bool hdlc_streaming_decode(HdlcStreamingContext *ctx, uint8_t *data, bool *complete,
                           bool *is_invalid);
bool hdlc_encode(uint8_t *data);
