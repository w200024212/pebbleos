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

#include "applib/graphics/framebuffer.h"
#include "util/attributes.h"

volatile const int FrameBuffer_MaxX = DISP_COLS;
volatile const int FrameBuffer_MaxY = DISP_ROWS;

void WEAK framebuffer_mark_dirty_rect(FrameBuffer *f, GRect rect) {}

void WEAK framebuffer_init(FrameBuffer *f, const GSize *size) { f->size = *size; }

GSize WEAK framebuffer_get_size(FrameBuffer *f) { return f->size; }
