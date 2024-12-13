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

#include "applib/graphics/text.h"

#define STUBBED_CREATED_LAYOUT (GTextLayoutCacheRef)123456

void WEAK graphics_text_layout_cache_init(GTextLayoutCacheRef *layout_cache) {
  *layout_cache = STUBBED_CREATED_LAYOUT;
}

void WEAK graphics_text_layout_cache_deinit(GTextLayoutCacheRef *layout_cache) {}
void WEAK graphics_text_layout_set_line_spacing_delta(GTextLayoutCacheRef layout, int16_t delta) {}

int16_t WEAK graphics_text_layout_get_line_spacing_delta(const GTextLayoutCacheRef layout) {
  return 0;
}

GSize WEAK graphics_text_layout_get_max_used_size(GContext *ctx, const char *text,
                                                  GFont const font, const GRect box,
                                                  const GTextOverflowMode overflow_mode,
                                                  const GTextAlignment alignment,
                                                  GTextLayoutCacheRef layout) {
  return GSizeZero;
}

void WEAK graphics_text_attributes_restore_default_text_flow(GTextLayoutCacheRef layout) {}

void WEAK graphics_text_attributes_enable_screen_text_flow(GTextLayoutCacheRef layout,
                                                           uint8_t inset) {}

void WEAK graphics_text_attributes_restore_default_paging(GTextLayoutCacheRef layout) {}

void WEAK graphics_text_attributes_enable_paging(GTextLayoutCacheRef layout,
                                                 GPoint content_origin_on_screen,
                                                 GRect paging_on_screen) {}
