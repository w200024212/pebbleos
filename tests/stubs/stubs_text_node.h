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

#include "apps/system_apps/timeline/text_node.h"

void graphics_text_node_destroy(GTextNode *node) { }

void graphics_text_node_get_size(GTextNode *node, GContext *ctx, const GRect *box,
                                 const GTextNodeDrawConfig *config, GSize *size_out) { }

void graphics_text_node_draw(GTextNode *node, GContext *ctx, const GRect *box,
                             const GTextNodeDrawConfig *config, GSize *size_out) { }

bool graphics_text_node_container_add_child(GTextNodeContainer *parent, GTextNode *child) {
  return 0;
}

GTextNodeText *graphics_text_node_create_text(size_t buffer_size) { return NULL; }
