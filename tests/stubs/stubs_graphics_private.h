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

#include "applib/graphics/graphics_private.h"

void graphics_private_set_pixel(GContext* ctx, GPoint point) {}

void graphics_private_draw_horizontal_line_integral(GContext *ctx, GBitmap *framebuffer, int16_t y,
                                                    int16_t x1, int16_t x2, GColor color) {}
