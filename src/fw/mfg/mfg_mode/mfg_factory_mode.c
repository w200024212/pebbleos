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

#include "mfg_factory_mode.h"

#include "apps/prf_apps/mfg_menu_app.h"
#include "board/board.h"
#include "kernel/event_loop.h"
#include "kernel/low_power.h"
#include "process_management/app_manager.h"
#include "services/prf/accessory/accessory_manager.h"
#include "services/prf/idle_watchdog.h"

static bool s_mfg_mode = false;

static void prv_launch_mfg_app(void *data) {
  // Make sure we can launch our MFG app and subsequent apps.
  app_manager_set_minimum_run_level(ProcessAppRunLevelNormal);
  app_manager_launch_new_app(&(AppLaunchConfig) {
    .md = mfg_menu_app_get_info(),
  });
}

void mfg_enter_mfg_mode(void) {
  if (!s_mfg_mode) {
    s_mfg_mode = true;

#if CAPABILITY_HAS_ACCESSORY_CONNECTOR
    accessory_manager_set_state(AccessoryInputStateMfg);
#endif

    prf_idle_watchdog_stop();

    low_power_exit();
  }
}

void mfg_enter_mfg_mode_and_launch_app(void) {
  if (!s_mfg_mode) {
    mfg_enter_mfg_mode();
    launcher_task_add_callback(prv_launch_mfg_app, NULL);
  }
}

bool mfg_is_mfg_mode(void) {
  return s_mfg_mode;
}

void command_enter_mfg(void) {
  mfg_enter_mfg_mode_and_launch_app();
}

