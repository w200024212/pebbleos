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

#include "fake_gbitmap_get_data_row.h"

#include "applib/graphics/gtypes.h"

#include <stdint.h>

bool s_fake_data_row_handling = false;
bool s_fake_data_row_handling_disable_vertical_flip = false;

extern GBitmapDataRowInfo prv_gbitmap_get_data_row_info(const GBitmap *bitmap, uint16_t y);

// Overrides the same function in gbitmap.c
GBitmapDataRowInfo gbitmap_get_data_row_info(const GBitmap *bitmap, uint16_t y) {
  // If fake data row handling is enabled, clip the row to a diamond mask
  if (s_fake_data_row_handling) {
    const int16_t diamond_offset =
        ABS((bitmap->bounds.size.w / 2) - (y * bitmap->bounds.size.w / bitmap->bounds.size.h));
    const int16_t min_x = bitmap->bounds.origin.x + diamond_offset;
    // vertically flip unless disabled
    if (!s_fake_data_row_handling_disable_vertical_flip) {
      y = bitmap->bounds.size.h - y - 1;
    }
    return (GBitmapDataRowInfo){
      .data = prv_gbitmap_get_data_row_info(bitmap, y).data,
      .min_x = min_x,
      .max_x = grect_get_max_x(&bitmap->bounds) - diamond_offset - 1,
    };
  }
  return prv_gbitmap_get_data_row_info(bitmap, y);
}
