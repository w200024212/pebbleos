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

#include "process_management/app_install_types.h"

//! @file shell_sdk.h
//!
//! Hooks into system_app_state_machine.c to watch for installed apps to be launched. Latches
//! so we can figure out what was the installed app that we've launched most recently.

AppInstallId shell_sdk_get_last_installed_app(void);

void shell_sdk_set_last_installed_app(AppInstallId app_id);

bool shell_sdk_last_installed_app_is_watchface();
