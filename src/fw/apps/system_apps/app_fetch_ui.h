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

#include "process_management/app_install_types.h"
#include "process_management/launch_config.h"
#include "process_management/pebble_process_md.h"
#include "services/common/compositor/compositor.h"
#include "services/normal/wakeup.h"

#include <stdbool.h>

typedef struct AppFetchUIArgs {
  LaunchConfigCommon common;
  WakeupInfo wakeup_info;
  AppInstallId app_id;
  bool forcefully; //! whether to launch forcefully or not
} AppFetchUIArgs;

//! Used to launch the app_fetch_ui application
const PebbleProcessMd *app_fetch_ui_get_app_info(void);
