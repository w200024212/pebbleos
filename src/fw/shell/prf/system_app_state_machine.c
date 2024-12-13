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

#include "shell/system_app_state_machine.h"

#include "apps/system_app_ids.h"
#include "apps/core_apps/panic_window_app.h"
#include "apps/prf_apps/mfg_menu_app.h"
#include "apps/prf_apps/recovery_first_use_app/recovery_first_use_app.h"
#include "kernel/panic.h"
#include "mfg/mfg_mode/mfg_factory_mode.h"
#include "process_management/app_manager.h"
#include "services/prf/accessory/accessory_imaging.h"

const PebbleProcessMd* system_app_state_machine_system_start(void) {
  if (launcher_panic_get_current_error() != 0) {
    return panic_app_get_app_info();
  }

#ifdef MANUFACTURING_FW
  accessory_imaging_enable();
  mfg_enter_mfg_mode();
  return mfg_menu_app_get_info();
#endif

  return recovery_first_use_app_get_app_info();
}

AppInstallId system_app_state_machine_get_last_registered_app(void) {
  if (mfg_is_mfg_mode()) {
    return APP_ID_MFG_MENU;
  }

  return APP_ID_RECOVERY_FIRST_USE;
}

const PebbleProcessMd* system_app_state_machine_get_default_app(void) {
  if (mfg_is_mfg_mode()) {
    return mfg_menu_app_get_info();
  }

  return recovery_first_use_app_get_app_info();
}

void system_app_state_machine_register_app_launch(AppInstallId app_id) {
}

void system_app_state_machine_panic(void) {
  if (app_manager_is_first_app_launched()) {
    app_manager_launch_new_app(&(AppLaunchConfig) {
      .md = panic_app_get_app_info(),
    });
  }
}

