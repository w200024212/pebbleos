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

#include "../launcher_app.h"

#include "launcher_menu_layer.h"

#include "applib/graphics/gtypes.h"

#include <stdbool.h>

typedef struct LauncherMenuArgs {
  bool reset_scroll;
} LauncherMenuArgs;

typedef struct LauncherDrawState {
  GRangeVertical selection_vertical_range;
  GColor selection_background_color;
} LauncherDrawState;

const LauncherDrawState *launcher_app_get_draw_state(void);
