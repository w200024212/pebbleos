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
#include "applib/graphics/graphics.h"
#include "applib/graphics/graphics_private_raw_mask.h"
#include "applib/graphics/framebuffer.h"
#include "util/graphics.h"

static uint8_t test_graphics_context_mask_get_value_for_coordinate(const GContext *ctx,
                                                                   const GDrawMask *mask,
                                                                   GPoint p) {
  const uint8_t mask_pixel_value = graphics_private_raw_mask_get_value(ctx, mask, p);

  cl_assert(WITHIN(mask_pixel_value, 0, (1 << (GDRAWMASK_BITS_PER_PIXEL)) - 1));

  return mask_pixel_value;
}

static void test_graphics_context_mask_set_value_for_coordinate(GContext *ctx, GDrawMask *mask,
                                                                uint8_t value, GPoint p) {
  cl_assert(WITHIN(value, 0, (1 << (GDRAWMASK_BITS_PER_PIXEL)) - 1));

  graphics_private_raw_mask_set_value(ctx, mask, p, value);
}

static void test_graphics_context_mask_debug(GContext *ctx, GDrawMask *mask) {
  GBitmap *framebuffer_bitmap = &ctx->dest_bitmap;

  // Naive approach
  for (int y = 0; y < framebuffer_bitmap->bounds.size.h; y++) {
    const GBitmapDataRowInfo current_data_row_info = gbitmap_get_data_row_info(framebuffer_bitmap,
                                                                               y);

    // Iterate over the relevant mask row pixel values and use each to draw our debug image
    for (int x = current_data_row_info.min_x; x <= current_data_row_info.max_x; x++) {
      const uint8_t mask_pixel_value =
        test_graphics_context_mask_get_value_for_coordinate(ctx, mask, GPoint(x, y));
      const GColor color_lookup[1 << GDRAWMASK_BITS_PER_PIXEL] = {
        GColorBlack,
        GColorDarkGray,
        GColorLightGray,
        GColorWhite,
      };
      const GColor pixel_color = color_lookup[mask_pixel_value];
      current_data_row_info.data[x] = pixel_color.argb;
    }
  }
}
