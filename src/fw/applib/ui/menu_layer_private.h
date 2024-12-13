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

#include "menu_layer.h"

struct MenuIterator;

typedef void (*MenuIteratorCallback)(struct MenuIterator *it);

typedef struct MenuIterator {
  MenuLayer * menu_layer;
  MenuCellSpan cursor;
  int16_t cell_bottom_y;
  MenuIteratorCallback row_callback_before_geometry;
  MenuIteratorCallback row_callback_after_geometry;
  MenuIteratorCallback section_callback;
  bool should_continue; // callback can set this to false if the row-loop should be exited.
} MenuIterator;

typedef struct MenuRenderIterator {
  MenuIterator it;
  GContext* ctx;
  int16_t content_top_y;
  int16_t content_bottom_y;
  bool cache_set:1;
  bool cursor_in_frame:1;
  MenuCellSpan new_cache;
  Layer cell_layer;
} MenuRenderIterator;
