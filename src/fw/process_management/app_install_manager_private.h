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
#include "app_install_manager.h"
#include "pebble_process_md.h"

//! @file app_install_manager_private.h
//! These are the "private" functions used by submodules of app_install_manager.

typedef void (*InstallCallbackDoneCallback)(void*);

//! Used by app_custom_icon and app_db, so invoke add/remove/update/app_db_clear callbacks.
//! This function takes care of calling the callbacks on the proper task, so this function
//! can be called from any task.
//! @return false if a callback is already in progress
bool app_install_do_callbacks(InstallEventType event_type, AppInstallId install_id, Uuid *uuid,
    InstallCallbackDoneCallback done_callback, void* done_callback_data);
