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

typedef struct GPerimeter GPerimeter;

//! @internal
typedef GRangeHorizontal (*GPerimeterCallback)(const GPerimeter *perimeter, const GSize *ctx_size,
                                               GRangeVertical vertical_range, uint16_t inset);

//! @internal
typedef struct GPerimeter {
  GPerimeterCallback callback;
} GPerimeter;

//! @internal
extern const GPerimeter * const g_perimeter_for_display;
