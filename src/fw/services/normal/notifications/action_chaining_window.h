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

#include "applib/ui/window_stack.h"
#include "services/normal/timeline/item.h"

typedef void (*ActionChainingMenuSelectCb)(Window *chaining_window,
                                           TimelineItemAction *action, void *context);
typedef void (*ActionChainingMenuClosedCb)(void *context);

void action_chaining_window_push(WindowStack *window_stack, const char *title,
                                 TimelineItemActionGroup *action_group,
                                 ActionChainingMenuSelectCb select_cb,
                                 void *select_cb_context,
                                 ActionChainingMenuClosedCb closed_cb,
                                 void *closed_cb_context);
