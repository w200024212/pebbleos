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

#include "action_button.h"

#include "applib/graphics/graphics.h"
#include "applib/preferred_content_size.h"

void action_button_draw(GContext *ctx, Layer *layer, GColor fill_color) {
  // This should match the window bounds
  const GRect bounds = layer->bounds;

  // Glue button to the right side of the window
  const int radius = PBL_IF_ROUND_ELSE(12, 13);
  GRect rect = { .size = { radius * 2, radius * 2 } };
  grect_align(&rect, &bounds, GAlignRight, false);

  // Offset the button halfway off-screen
  rect.origin.x += radius;

  // Further offset the button on a per-default-content-size basis
  // Note that this will need to be updated if we ever want ActionButton to adapt to the user's
  // preferred content size
  rect.origin.x += PREFERRED_CONTENT_SIZE_SWITCH(PreferredContentSizeDefault,
    //! @note this is the same as Medium until Small is designed
    /* small */ PBL_IF_ROUND_ELSE(1, 8),
    /* medium */ PBL_IF_ROUND_ELSE(1, 8),
    /* large */ 4,
    //! @note this is the same as Large until ExtraLarge is designed
    /* extralarge */ 4);

  graphics_context_set_fill_color(ctx, fill_color);
  graphics_fill_oval(ctx, rect, GOvalScaleModeFitCircle);
}

void action_button_update_proc(Layer *action_button_layer, GContext *ctx) {
  action_button_draw(ctx, action_button_layer, GColorBlack);
}
