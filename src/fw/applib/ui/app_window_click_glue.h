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

#include "process_management/app_manager.h"
#include "applib/ui/click_internal.h"

////////////////////////////////////////////////
// App + Click Recognizer + Window = Glue code

//! Calls the provider function of the window with the ClickConfig structs of the "app global" click recognizers.
//! The window is set as context to of each of the ClickConfig's .context fields for convenience.
//! In case window has a click_config_context set, it will use that as context instead of the window itself.
//! @see AppContext.click_recognizer[]
struct Window;

void app_click_config_setup_with_window(ClickManager* click_manager, struct Window *window);

