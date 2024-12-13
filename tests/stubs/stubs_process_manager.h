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

#include "applib/platform.h"
#include "process_management/process_manager.h"
#include "stubs_compiled_with_legacy2_sdk.h"
#include "util/attributes.h"
#include "stubs_compiled_with_legacy2_sdk.h"

const PebbleProcessMd *WEAK sys_process_manager_get_current_process_md(void) {
  return NULL;
}

bool WEAK sys_process_manager_get_current_process_uuid(Uuid *uuid_out) {
  return false;
}

bool WEAK process_manager_compiled_with_legacy3_sdk(void) {
  return false;
}

PlatformType WEAK process_manager_current_platform(void) {
  return PBL_PLATFORM_TYPE_CURRENT;
}

void WEAK process_manager_put_kill_process_event(PebbleTask task, bool gracefully) {
  return;
}

const void* WEAK process_manager_get_current_process_args(void) {
  return NULL;
}

bool WEAK process_manager_send_event_to_process(PebbleTask task, PebbleEvent *e) {
  return true;
}

void WEAK process_manager_send_callback_event_to_process(PebbleTask task,
                                                         void (*callback)(void *data),
                                                         void *data) {
  callback(data);
}

