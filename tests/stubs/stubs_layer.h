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

#include "applib/ui/layer.h"

#include "util/attributes.h"

#include "stubs_unobstructed_area.h"

WEAK void layer_init(Layer *layer, const GRect *frame) { }

WEAK void layer_add_child(Layer *parent, Layer *child) { }

WEAK void layer_mark_dirty(Layer *layer) { }

WEAK void layer_set_update_proc(Layer *layer, LayerUpdateProc update_proc) { }

WEAK bool layer_is_status_bar_layer(Layer *layer) {
  return false;
}
