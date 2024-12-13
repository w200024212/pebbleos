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

#include "rocky_api.h"

#include <stddef.h>

#include "rocky_api_app_message.h"
#include "rocky_api_console.h"
#include "rocky_api_datetime.h"
#include "rocky_api_global.h"
#include "rocky_api_graphics.h"
#include "rocky_api_memory.h"
#include "rocky_api_preferences.h"
#include "rocky_api_tickservice.h"
#include "rocky_api_timers.h"
#include "rocky_api_watchinfo.h"

void rocky_api_watchface_init(void) {
  static const RockyGlobalAPI *const apis[] = {
#if !APPLIB_EMSCRIPTEN
    &APP_MESSAGE_APIS,
    &CONSOLE_APIS,
#endif

    &DATETIME_APIS,
    &GRAPHIC_APIS,

#if !APPLIB_EMSCRIPTEN
    &MEMORY_APIS,
    &PREFERENCES_APIS,
#endif

    &TICKSERVICE_APIS,

#if !APPLIB_EMSCRIPTEN
    &TIMER_APIS,
    &WATCHINFO_APIS,
#endif

    NULL,
  };
  rocky_global_init(apis);
}

void rocky_api_deinit(void) {
  rocky_global_deinit();
}
