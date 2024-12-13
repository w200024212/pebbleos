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

#define FAKE_GRAPHICS_CONTEXT_C (1)

#include "fake_graphics_context.h"

#include "applib/graphics/graphics.h"
#include "applib/graphics/framebuffer.h"

extern GContext *s_app_state_get_graphics_context;

static GContext s_ctx;
static FrameBuffer s_fb;

GContext *graphics_context_get_current_context(void) {
  return &s_ctx;
}

GContext *fake_graphics_context_get_context(void) {
  return &s_ctx;
}

FrameBuffer *fake_graphics_context_get_framebuffer(void) {
  return &s_fb;
}

void fake_graphics_context_init(void) {
  framebuffer_init(&s_fb, &(GSize) {DISP_COLS, DISP_ROWS});
  framebuffer_clear(&s_fb);
  graphics_context_init(&s_ctx, &s_fb, GContextInitializationMode_App);
  s_app_state_get_graphics_context = &s_ctx;
}
