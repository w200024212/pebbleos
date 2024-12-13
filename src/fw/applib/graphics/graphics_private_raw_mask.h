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

#include "gtypes.h"

extern const GDrawRawImplementation g_mask_recording_draw_implementation;

void graphics_private_raw_mask_apply(GColor8 *dst_color, const GDrawMask *mask,
                                     unsigned int data_row_offset, int x, int width,
                                     GColor8 src_color);

uint8_t graphics_private_raw_mask_get_value(const GContext *ctx, const GDrawMask *mask, GPoint p);

void graphics_private_raw_mask_set_value(const GContext *ctx, GDrawMask *mask, GPoint p,
                                         uint8_t value);
