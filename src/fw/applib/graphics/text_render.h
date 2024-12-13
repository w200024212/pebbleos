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

#include "applib/fonts/codepoint.h"
#include "applib/fonts/fonts_private.h"
#include "applib/graphics/gtypes.h"

#include "gtypes.h"

#include <inttypes.h>

typedef struct GContext GContext;

typedef void (*SpecialCodepointHandlerCb)(GContext *ctx, Codepoint codepoint, GRect cursor,
              void *context);

void render_glyph(GContext* const ctx, const uint32_t codepoint, FontInfo* const font,
                  const GRect cursor);

// This function sets a handler callback for handling special codepoints encountered during text
// rendering. This allows special draw operations at the cursor position that the codepoint occurs.
// This must be set to NULL when the window using it goes out of focus.
void text_render_set_special_codepoint_cb(SpecialCodepointHandlerCb handler, void *context);
