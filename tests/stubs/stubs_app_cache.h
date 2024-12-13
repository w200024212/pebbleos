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

AppInstallId app_cache_get_next_eviction(void) {
  return 0;
}

void app_cache_init(void) {
  return;
}

status_t app_cache_add_entry(AppInstallId app_id) {
  return 0;
}

status_t app_cache_entry_exists(AppInstallId app_id) {
  return true;
}

status_t app_cache_app_launched(AppInstallId app_id) {
  return 0;
}

status_t app_cache_remove_entry(AppInstallId app_id) {
  return 0;
}

void app_cache_flush(void) {
  return;
}
