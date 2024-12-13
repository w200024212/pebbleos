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

#include "applib/graphics/graphics.h"
#include "applib/graphics/graphics_private.h"
#include "applib/graphics/graphics_private_raw.h"
#include "applib/graphics/framebuffer.h"
#include "util/trig.h"

#include "applib/ui/window_private.h"
#include "applib/ui/layer.h"


#include "clar.h"
#include "util.h"

#include <stdio.h>

// Helper Functions
////////////////////////////////////
#include "test_graphics.h"
#include "8bit/test_framebuffer.h"

// Stubs
////////////////////////////////////
#include "graphics_common_stubs.h"
#include "stubs_applib_resource.h"

static FrameBuffer *fb = NULL;

#define CLIP_RECT_DRAW_BOX GRect(0, 0, DISP_COLS, DISP_ROWS)
#define CLIP_RECT_CLIP_BOX GRect(0, 0, DISP_COLS, DISP_ROWS)

// Setup and Teardown
////////////////////////////////////

// Setup
void test_framebuffer_clipping__initialize(void) {
  fb = malloc(sizeof(FrameBuffer));
  framebuffer_init(fb, &(GSize) { DISP_COLS, DISP_ROWS });
}

// Teardown
void test_framebuffer_clipping__cleanup(void) {
  free(fb);
}

// Tests
////////////////////////////////////

void test_framebuffer_clipping__off_screen_left_aa_clipping(void) {
  cl_assert_equal_i(GBITMAP_NATIVE_FORMAT, GBitmapFormat8BitCircular);

  GContext ctx;
  test_graphics_context_init(&ctx, fb);
  setup_test_aa_sw(&ctx, fb, CLIP_RECT_CLIP_BOX, CLIP_RECT_DRAW_BOX, true, 1);

  cl_assert_equal_i(ctx.dest_bitmap.info.format, GBitmapFormat8BitCircular);

  memset(ctx.dest_bitmap.addr, GColorRedARGB8, FRAMEBUFFER_SIZE_BYTES);

  GRect radial_container_rect = ctx.dest_bitmap.bounds;
  radial_container_rect = grect_inset(radial_container_rect, GEdgeInsets(-10));
  const uint16_t inset_thickness = radial_container_rect.size.w / 4;
  graphics_context_set_fill_color(&ctx, GColorGreen);
  graphics_fill_radial(&ctx, radial_container_rect, GOvalScaleModeFillCircle, inset_thickness,
                       TRIG_MAX_ANGLE / 2, TRIG_MAX_ANGLE);

  cl_check(gbitmap_pbi_eq(&ctx.dest_bitmap, TEST_NAMED_PBI_FILE("off_screen_left_aa_clipping")));
};

void test_framebuffer_clipping__off_screen_right_aa_clipping(void) {
  cl_assert_equal_i(GBITMAP_NATIVE_FORMAT, GBitmapFormat8BitCircular);

  GContext ctx;
  test_graphics_context_init(&ctx, fb);
  setup_test_aa_sw(&ctx, fb, CLIP_RECT_CLIP_BOX, CLIP_RECT_DRAW_BOX, true, 1);
  cl_assert_equal_i(ctx.dest_bitmap.info.format, GBitmapFormat8BitCircular);

  memset(ctx.dest_bitmap.addr, GColorRedARGB8, FRAMEBUFFER_SIZE_BYTES);

  GRect radial_container_rect = ctx.dest_bitmap.bounds;
  radial_container_rect = grect_inset(radial_container_rect, GEdgeInsets(-10));
  const uint16_t inset_thickness = radial_container_rect.size.w / 4;
  graphics_context_set_fill_color(&ctx, GColorGreen);
  graphics_fill_radial(&ctx, radial_container_rect, GOvalScaleModeFillCircle, inset_thickness, 0,
                       TRIG_MAX_ANGLE / 2);

  cl_check(gbitmap_pbi_eq(&ctx.dest_bitmap, TEST_NAMED_PBI_FILE("off_screen_right_aa_clipping")));
};
