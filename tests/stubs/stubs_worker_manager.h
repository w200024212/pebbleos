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
#include "process_management/process_manager.h"

// Worker management functions
void worker_manager_init(void) {
}

bool worker_manager_launch_new_worker_with_args(const PebbleProcessMd *app_md, const void *args) {
  return false;
}

void worker_manager_close_current_worker(bool gracefully) {
}

const PebbleProcessMd* worker_manager_get_current_worker_md(void) {
  return NULL;
}

static ProcessContext s_worker_task_context;
ProcessContext* worker_manager_get_task_context(void) {
  return &s_worker_task_context;
}


void worker_manager_put_launch_worker_event(AppInstallId id) {
}

//! Get the AppInstallId of the default worker to launch. Returns INSTALL_ID_INVALID if none set. 
AppInstallId worker_manager_get_default_install_id(void) {
  return 0;
}

AppInstallId worker_manager_get_current_worker_id(void) {
  return 0;
}

AppInstallId sys_worker_manager_get_current_worker_id(void) {
  return 0;
}

void worker_manager_handle_remove_current_worker(void) {
}
