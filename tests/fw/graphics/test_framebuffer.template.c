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

#include "applib/graphics/graphics.h"
#include "applib/graphics/framebuffer.h"

#include "util/bitset.h"
#include "util/size.h"
#include "${BIT_DEPTH_NAME}/test_framebuffer.h"

#include "clar.h"

// Stubs
////////////////////////////////////
#include "graphics_common_stubs.h"
#include "stubs_applib_resource.h"

// Setup
////////////////////////////////////
static FrameBuffer framebuffer;

// Tests
////////////////////////////////////

void test_framebuffer_${BIT_DEPTH_NAME}__framebuffer_clear(void) {
  // clear the framebuffer
  framebuffer_init(&framebuffer, &(GSize) { DISP_COLS, DISP_ROWS });
  framebuffer_clear(&framebuffer);

  // check the clearing
#if SCREEN_COLOR_DEPTH_BITS == 1
  for (int i = 0; i < ARRAY_LENGTH(framebuffer.buffer); i++) {
    cl_assert(framebuffer.buffer[i] == 0xffffffff);
  }
#elif SCREEN_COLOR_DEPTH_BITS == 8
  for (int i = 0; i < ARRAY_LENGTH(framebuffer.buffer); i++) {
    cl_assert(framebuffer.buffer[i] == GColorWhite.argb);
  }
  GRect expected_dirty = GRect(0, 0, DISP_COLS, DISP_ROWS);
#else
  cl_assert(!memcmp(&framebuffer.dirty_rect, &expected_dirty, sizeof(GRect)));
  cl_assert(false);
#endif

  cl_assert(framebuffer.is_dirty == true);
}
