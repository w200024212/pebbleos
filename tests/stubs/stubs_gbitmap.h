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

uint8_t gbitmap_get_bits_per_pixel(GBitmapFormat format){return 0;}

void gbitmap_destroy(GBitmap* bitmap){}

GBitmapFormat gbitmap_get_format(const GBitmap *bitmap) {
  return bitmap->info.format;
}

GBitmap *gbitmap_create_with_resource_system(ResAppNum app_num, uint32_t resource_id) {
  return NULL;
}

GBitmap *gbitmap_create_with_data(const uint8_t *data){ return NULL; }

GBitmap *gbitmap_create_blank(GSize size, GBitmapFormat format) { return NULL; }

GBitmapDataRowInfo gbitmap_get_data_row_info(const GBitmap *bitmap, uint16_t y) {
  return (GBitmapDataRowInfo) {0};
}

uint16_t gbitmap_format_get_row_size_bytes(int16_t width, GBitmapFormat format) {
  return width;
}

GRect gbitmap_get_bounds(const GBitmap *bitmap) {
  return bitmap->bounds;
}
