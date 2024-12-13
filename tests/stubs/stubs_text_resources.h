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

#include "applib/fonts/fonts_private.h"
#include "applib/graphics/text_resources.h"
#include "applib/fonts/codepoint.h"

#include <inttypes.h>
#include <stdbool.h>

#define HORIZ_ADVANCE_PX (2)

bool text_resources_setup_font(FontCache* font_cache, FontInfo* fontinfo) {
  return true;
}

int8_t text_resources_get_glyph_horiz_advance(FontCache* font_cache, Codepoint codepoint, FontInfo* fontinfo) {
  if (codepoint_is_zero_width(codepoint)) {
    return 0;
  }
  // Real fonts have some weird values here, give something totally bogus for testing.
  if (codepoint == '\n') {
    return 5;
  }
  return HORIZ_ADVANCE_PX;
}

int8_t text_resources_get_glyph_height(FontCache* font_cache, Codepoint codepoint, FontInfo* fontinfo) {
  return 10;
}

