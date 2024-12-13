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
#include "process_state/app_state/app_state.h"

void emx_graphics_init(void);
GContext *emx_graphics_get_gcontext(void);
void *emx_graphics_get_pixes(void);
TextRenderState *app_state_get_text_render_state(void);
void emx_graphics_call_canvas_update_proc(void);
