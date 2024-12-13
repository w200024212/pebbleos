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

GfxTest g_gfx_test_gpath_masking = {
  .name = "GPath masking",
  .duration = 1,
  .unit_multiple = 1,
  .test_proc = prv_test,
};

static const GPathInfo s_triangle_mask = {
  .num_points = 3,
  .points = (GPoint[]) {
    {0, 0},
    {50, 50},
    {50, -50}
  }
};

static void prv_test(Layer *layer, GContext* ctx) {
  GRect bounds = layer->bounds;
  GPoint center = GPoint(bounds.size.w/2, bounds.size.h/2);
  int outer_radius = 50;
  int inner_radius = 35;

  GPath *mask = gpath_create(&s_triangle_mask);
  gpath_move_to(mask, center);

  GColor color = { .argb = (uint8_t) rand() };
  GColor bg_color = { .argb = (uint8_t) rand() };
  graphics_context_set_fill_color(ctx, color);
  graphics_fill_circle(ctx, center, outer_radius);

  graphics_context_set_fill_color(ctx, bg_color);
  graphics_fill_circle(ctx, center, inner_radius);
  gpath_draw_filled(ctx, mask);
}
