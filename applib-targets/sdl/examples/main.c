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

#include <stdio.h>

#include "sdl_graphics.h"
#include "sdl_app.h"

#include "applib/app.h"
#include "applib/graphics/gtypes.h"
#include "applib/graphics/graphics.h"
#include "applib/graphics/graphics_line.h"


int main(void) {
  GContext *context = sdl_graphics_get_gcontext();
  graphics_context_set_stroke_color(context, GColorBrightGreen);
  graphics_context_set_stroke_width(context, 2);
  graphics_draw_line(context, (GPoint){0, 0}, (GPoint){100, 100});
  graphics_draw_line(context, (GPoint){0, 10}, (GPoint){100, 10});
  graphics_draw_line(context, (GPoint){0, 20}, (GPoint){100, 20});
  graphics_draw_line(context, (GPoint){0, 30}, (GPoint){100, 30});
  graphics_draw_circle(context, (GPoint){50, 50}, 20);
  app_event_loop();

  return 0;
}
