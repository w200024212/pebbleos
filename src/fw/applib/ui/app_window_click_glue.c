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

#include "app_window_click_glue.h"

#include "process_state/app_state/app_state.h"
#include "applib/ui/click_internal.h"
#include "applib/ui/window.h"
#include "applib/ui/window_stack_private.h"
#include "system/passert.h"
#include "util/size.h"

////////////////////////////////////////////////
// App + Click Recognizer + Window : Glue code
//
// [MT] This is a bit ugly, because I decided to to save memory and have all windows in an app share an array of
// click recognizers (which lives in AppContext) instead of each window having its own.
// See the comment near AppContext.click_recognizer.

void app_click_config_setup_with_window(ClickManager *click_manager, struct Window *window) {
  void *context = window->click_config_context;
  if (!context) {
    // Default context is the window.
    context = window;
  }

  click_manager_clear(click_manager);

  for (unsigned int button_id = 0; button_id < NUM_BUTTONS; ++button_id) {
    // For convenience, assign the context:
    click_manager->recognizers[button_id].config.context = context;
  }

  if (window->click_config_provider) {
    window_call_click_config_provider(window, context);
  }
}

