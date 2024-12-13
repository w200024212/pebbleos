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

#include "applib/graphics/gtypes.h"
#include "drivers/display/display.h"
#include "util/attributes.h"

#include <stdint.h>
#include <stdbool.h>

#define FRAMEBUFFER_BYTES_PER_ROW DISP_COLS
#define FRAMEBUFFER_SIZE_BYTES DISPLAY_FRAMEBUFFER_BYTES

#ifndef UNITTEST
typedef struct FrameBuffer {
  uint8_t buffer[FRAMEBUFFER_SIZE_BYTES];
  GSize size; //<! Active size of the framebuffer
  GRect dirty_rect; //<! Smallest rect covering all dirty pixels.
  bool is_dirty;
} FrameBuffer;
#else // UNITTEST
// For unit-tests, the framebuffer buffer is moved to the end of the struct
// and packed to allow for DUMA to catch memory overflows
typedef struct PACKED FrameBuffer {
  GSize size; //<! Active size of the framebuffer
  GRect dirty_rect; //<! Smallest rect covering all dirty pixels.
  bool is_dirty;
  uint8_t buffer[FRAMEBUFFER_SIZE_BYTES];
} FrameBuffer;
#endif

uint8_t* framebuffer_get_line(FrameBuffer* f, uint8_t y);
