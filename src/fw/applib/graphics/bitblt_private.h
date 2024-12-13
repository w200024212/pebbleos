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

#include "bitblt.h"

void bitblt_bitmap_into_bitmap_tiled_1bit_to_1bit(
    GBitmap* dest_bitmap, const GBitmap* src_bitmap, GRect dest_rect,
    GPoint src_origin_offset, GCompOp compositing_mode, GColor tint_color);

void bitblt_bitmap_into_bitmap_tiled_1bit_to_8bit(
    GBitmap* dest_bitmap, const GBitmap* src_bitmap, GRect dest_rect,
    GPoint src_origin_offset, GCompOp compositing_mode, GColor8 tint_color);

void bitblt_bitmap_into_bitmap_tiled_8bit_to_8bit(
    GBitmap* dest_bitmap, const GBitmap* src_bitmap, GRect dest_rect,
    GPoint src_origin_offset, GCompOp compositing_mode, GColor8 tint_color);

// Used when source bitmap is 1 bit and the destination is 1 or 8 bit.
// Sets up the GCompOp based on the tint_color.
void bitblt_into_1bit_setup_compositing_mode(GCompOp *compositing_mode, GColor tint_color);

extern const GColor8Component g_bitblt_private_blending_mask_lookup[];
