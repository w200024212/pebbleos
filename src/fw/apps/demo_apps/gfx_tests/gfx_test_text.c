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

static void prv_setup(Window *window);
static void prv_test(Layer *layer, GContext* ctx);

GfxTest g_gfx_test_text = {
  .name = "Text",
  .duration = 5,
  .unit_multiple = 0,  // Number of characters in test string - set later
  .test_proc = prv_test,
  .setup = prv_setup,
};

static GFont s_font;

static void prv_setup(Window *window) {
  s_font = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
}

static void prv_test(Layer *layer, GContext* ctx) {
  const char *text_test_str = "Lorem ipsum dolor sit amet, ne choro argumentum est, quando latine "
                              "copiosae est ea, usu nonumes accusam te.";
  g_gfx_test_text.unit_multiple = strlen(text_test_str);
  GColor color = { .argb = (uint8_t) rand() };
  graphics_context_set_text_color(ctx, color);
  graphics_draw_text(ctx, text_test_str, s_font, layer->bounds,
      GTextOverflowModeWordWrap, GTextAlignmentLeft, NULL);
}
