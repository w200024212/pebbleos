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

#include "process_management/pebble_process_md.h"
#include "process_management/app_install_types.h"

//! Get the very first app we should run at startup.
const PebbleProcessMd* system_app_state_machine_system_start(void);

//! Retrieve the app that was last launched prior to the current one.
AppInstallId system_app_state_machine_get_last_registered_app(void);

//! Get the app we should launch after an app has crashed or has been force quit.
const PebbleProcessMd* system_app_state_machine_get_default_app(void);

//! Tell the state machine we just launched an app.
void system_app_state_machine_register_app_launch(AppInstallId app_id);

//! Stop the normal state machine! Just show the panic app.
void system_app_state_machine_panic(void);

