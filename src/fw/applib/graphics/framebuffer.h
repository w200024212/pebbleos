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

#if SCREEN_COLOR_DEPTH_BITS == 8
#include "applib/graphics/8_bit/framebuffer.h"
#else
#include "applib/graphics/1_bit/framebuffer.h"
#endif

#include <stdint.h>
#include <stdbool.h>

extern volatile const int FrameBuffer_MaxX;
extern volatile const int FrameBuffer_MaxY;

//! Initializes the framebuffer by setting the size.
void framebuffer_init(FrameBuffer *fb, const GSize *size);

//! Get the active buffer size in bytes
size_t framebuffer_get_size_bytes(FrameBuffer *f);

//! Clears the screen buffer.
//! Will not be visible on the display until graphics_flush_frame_buffer is called.
void framebuffer_clear(FrameBuffer* f);

//! Mark the given rect of pixels as dirty
void framebuffer_mark_dirty_rect(FrameBuffer* f, GRect rect);

//! Mark the entire framebuffer as dirty
void framebuffer_dirty_all(FrameBuffer* f);

//! Clear the dirty status for this framebuffer
void framebuffer_reset_dirty(FrameBuffer* f);

//! Query the dirty status for this framebuffer
bool framebuffer_is_dirty(FrameBuffer* f);

//! Creates a GBitmap struct that points to the framebuffer. Useful for using the framebuffer data
//! with graphics routines. Note that updating this bitmap won't mark the appropriate lines as
//! dirty in the framebuffer, so this will have to be done manually.
//! @note The size which is passed in should come from app_manager_get_framebuffer_size() for the
//! app framebuffer (or generated based on DISP_ROWS / DISP_COLS for the system framebuffer) to
//! protect against malicious apps changing their own framebuffer size.
GBitmap framebuffer_get_as_bitmap(FrameBuffer *f, const GSize *size);

//! Get the framebuffer size
GSize framebuffer_get_size(FrameBuffer *f);
