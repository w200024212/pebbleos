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

#include "hdlc.h"

#include "system/passert.h"


void hdlc_streaming_decode_reset(HdlcStreamingContext *ctx) {
  ctx->escape = false;
}

bool hdlc_streaming_decode(HdlcStreamingContext *ctx, uint8_t *data, bool *should_store,
                           bool *hdlc_error) {
  PBL_ASSERTN(data != NULL && should_store != NULL && hdlc_error != NULL);
  bool is_complete = false;
  *hdlc_error = false;
  *should_store = false;
  if (*data == HDLC_FLAG) {
    if (ctx->escape) {
      // extra escape character before flag
      ctx->escape = false;
      *hdlc_error = true;
    }
    // we've reached the end of the frame
    is_complete = true;
  } else if (*data == HDLC_ESCAPE) {
    if (ctx->escape) {
      // invalid sequence
      ctx->escape = false;
      *hdlc_error = true;
    } else {
      // ignore this character and escape the next one
      ctx->escape = true;
    }
  } else {
    if (ctx->escape) {
      *data ^= HDLC_ESCAPE_MASK;
      ctx->escape = false;
    }
    *should_store = true;
  }

  return is_complete;
}

bool hdlc_encode(uint8_t *data) {
  if (*data == HDLC_FLAG || *data == HDLC_ESCAPE) {
    *data ^= HDLC_ESCAPE_MASK;
    return true;
  }
  return false;
}
