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

#include "applib/graphics/gtypes.h"
#include "upng.h"

bool gbitmap_png_data_is_png(uint8_t *data, size_t data_size) {return false;}

GBitmap* gbitmap_create_from_png_data(const uint8_t *png_data, size_t png_data_size) {return NULL;}

bool gbitmap_init_with_png_data(GBitmap *bitmap, const uint8_t *data, size_t data_size) {return true;}

uint8_t gbitmap_png_load_palette(upng_t *upng, GColor8 **palette) {return 0;}

bool gbitmap_png_is_format_supported(upng_t *upng) {return true;}

int32_t gbitmap_png_get_transparent_gray_value(upng_t *upng) {return -1;}

int32_t png_seek_chunk_in_resource(uint32_t resource_id, uint32_t offset,
                                   bool seek_framedata, bool *found_actl) {return 0;}

int32_t png_seek_chunk_in_resource_system(ResAppNum app_num, uint32_t resource_id, uint32_t offset,
                                          bool seek_framedata, bool *found_actl) {return 0;}
