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

#include "applib/graphics/framebuffer.h"

#include "applib/graphics/gtypes.h"
#include "system/logging.h"
#include "system/passert.h"
#include "util/bitset.h"

#include <stdint.h>
#include <string.h>

volatile const int FrameBuffer_MaxX = DISP_COLS;
volatile const int FrameBuffer_MaxY = DISP_ROWS;
volatile const int FrameBuffer_BytesPerRow = FRAMEBUFFER_BYTES_PER_ROW;

uint32_t *framebuffer_get_line(FrameBuffer *f, uint8_t y) {
  PBL_ASSERTN(y < f->size.h);

  return f->buffer + (y * ((f->size.w / 32) + 1));
}

inline size_t framebuffer_get_size_bytes(FrameBuffer *f) {
  // TODO: Make FRAMEBUFFER_SIZE_BYTES a macro which takes the cols and rows if we ever want to
  // support different size framebuffers for watches which have native 1-bit framebuffers where the
  // size is not just COLS * ROWS.
  return FRAMEBUFFER_SIZE_BYTES;
}

void framebuffer_clear(FrameBuffer *f) {
  memset(f->buffer, 0xff, framebuffer_get_size_bytes(f));
  framebuffer_dirty_all(f);
  f->is_dirty = true;
}

void framebuffer_mark_dirty_rect(FrameBuffer *f, GRect rect) {
  if (!f->is_dirty) {
    f->dirty_rect = rect;
  } else {
    f->dirty_rect = grect_union(&f->dirty_rect, &rect);
  }

  const GRect clip_rect = (GRect) { GPointZero, f->size };
  grect_clip(&f->dirty_rect, &clip_rect);

  f->is_dirty = true;
}
