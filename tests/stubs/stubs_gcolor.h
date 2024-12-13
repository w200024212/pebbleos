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

#include "applib/graphics/gtypes.h"
#include "util/attributes.h"

bool WEAK gcolor_equal(GColor8 x, GColor8 y) {
  return ((x.argb == y.argb) || ((x.a == 0) && (y.a == 0)));
}

GColor8 WEAK gcolor_legible_over(GColor8 background_color) {
  return GColorBlack;
}

