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

#include <stdbool.h>
#include <stdint.h>

typedef struct {
  const uint8_t *sle_buffer;
  uint16_t zeros_remaining;
  uint8_t escape;
} SLEDecodeContext;

//! Initialize the decode context to decode the given buffer.
void sle_decode_init(SLEDecodeContext *ctx, const void *sle_buffer);

//! Decode the next byte in the incoming buffer.
bool sle_decode(SLEDecodeContext *ctx, uint8_t *out);
