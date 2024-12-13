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

#include "applib/ui/property_animation.h"
#include "util/attributes.h"

bool WEAK property_animation_from(PropertyAnimation *property_animation, void *from, size_t size,
                                  bool set) {
  return false;
}

void WEAK property_animation_update_grect(PropertyAnimation *property_animation,
                                          const uint32_t distance_normalized) {}

PropertyAnimation *WEAK property_animation_create_layer_bounds(
    struct Layer *layer, GRect *from_bounds, GRect *to_bounds) {
  return NULL;
}

PropertyAnimation *WEAK property_animation_create_bounds_origin(
    struct Layer *layer, GPoint *from, GPoint *to) {
  return NULL;
}
