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

#include "gtypes.h"

void bitblt_bitmap_into_bitmap_tiled(GBitmap* dest_bitmap, const GBitmap* src_bitmap,
                                     GRect dest_rect, GPoint src_origin_offset,
                                     GCompOp compositing_mode, GColor tint_color);

void bitblt_bitmap_into_bitmap(GBitmap* dest_bitmap, const GBitmap* src_bitmap, GPoint dest_offset,
                               GCompOp compositing_mode, GColor tint_color);

bool bitblt_compositing_mode_is_noop(GCompOp compositing_mode, GColor tint_color);
