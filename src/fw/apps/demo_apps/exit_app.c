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

#include "exit_app.h"
#include "applib/app_logging.h"

// Verify that applications can actually call stdlib's exit().
static void s_exit_app_main(void) {

  // Make visible in the debugger if we are running privileged.
  uint32_t value;
   __asm volatile("mrs %0, control" : "=r" (value));
  volatile bool is_privileged = !(value & 0x1);
  APP_LOG(LOG_LEVEL_DEBUG, "Exit app is %sprivileged; now exiting", is_privileged ? "" : "not ");
}

const PebbleProcessMd *exit_app_get_app_info(void) {
  static const PebbleProcessMdSystem s_exit_app_info = {
    .common.main_func = s_exit_app_main,
    .common.is_unprivileged = true,
    .name = "Exit Test"
  };
  return (const PebbleProcessMd*) &s_exit_app_info;
}

