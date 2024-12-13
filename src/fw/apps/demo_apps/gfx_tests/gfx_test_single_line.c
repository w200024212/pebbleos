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

#include "gfx_tests.h"

static void prv_test(Layer *layer, GContext* ctx);

GfxTest g_gfx_test_single_line = {
  .name = "Single line",
  .duration = 1,
  .unit_multiple = 1,
  .test_proc = prv_test,
};

static void prv_test(Layer *layer, GContext* ctx) {
  GRect bounds = layer->bounds;
  int16_t x1 = (rand() % bounds.size.w) + bounds.origin.x;
  int16_t x2 = (rand() % bounds.size.w) + bounds.origin.x;
  int16_t y1 = (rand() % bounds.size.h) + bounds.origin.y;
  int16_t y2 = (rand() % bounds.size.h) + bounds.origin.y;

  GColor color = { .argb = (uint8_t) rand() };
  graphics_context_set_stroke_color(ctx, color);
  graphics_draw_line(ctx, (GPoint){.x = x1, .y = y1}, (GPoint) {.x = x2, .y = y2});
}
