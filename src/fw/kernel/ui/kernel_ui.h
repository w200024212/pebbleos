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
#include "applib/ui/content_indicator_private.h"
#include "services/normal/timeline/timeline_actions.h"

void kernel_ui_init(void);

GContext* kernel_ui_get_graphics_context(void);

GContext *graphics_context_get_current_context(void);

ContentIndicatorsBuffer *kernel_ui_get_content_indicators_buffer(void);

ContentIndicatorsBuffer *content_indicator_get_current_buffer(void);

TimelineItemActionSource kernel_ui_get_current_timeline_item_action_source(void);
void kernel_ui_set_current_timeline_item_action_source(TimelineItemActionSource current_source);
