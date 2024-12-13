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

#include "applib/graphics/graphics.h"
#include "util/attributes.h"

void WEAK graphics_fill_circle(GContext* ctx, GPoint p, uint16_t radius) {}

void WEAK graphics_fill_rect(GContext* ctx, const GRect *rect) {}

void WEAK graphics_fill_round_rect(GContext* ctx, const GRect *rect, uint16_t radius,
                                   GCornerMask corner_mask) {}

void WEAK graphics_draw_circle(GContext* ctx, GPoint p, uint16_t radius) {}

void WEAK graphics_draw_bitmap_in_rect_processed(GContext* ctx, const GBitmap *src_bitmap,
                                                 const GRect *rect, GBitmapProcessor *processor) {}

void WEAK graphics_draw_text(GContext* ctx, const char* text, GFont const font,
                             GRect box, const GTextOverflowMode overflow_mode,
                             const GTextAlignment alignment, GTextLayoutCacheRef const layout) {}

GBitmap *WEAK graphics_capture_frame_buffer(GContext* ctx) { return NULL; }

bool WEAK graphics_release_frame_buffer(GContext* ctx, GBitmap* buffer) { return true; }
