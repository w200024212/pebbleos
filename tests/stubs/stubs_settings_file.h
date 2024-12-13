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

#include "services/normal/settings/settings_file.h"

status_t settings_file_open(SettingsFile *file, const char *name, int max_used_space) {
  return S_SUCCESS;
}

status_t settings_file_get(SettingsFile *file, const void *key, size_t key_len,
                           void *val_out, size_t val_out_len) {
  return S_SUCCESS;
}

status_t settings_file_set(SettingsFile *file, const void *key, size_t key_len,
                           const void *val, size_t val_len) {
  return S_SUCCESS;
}

status_t settings_file_each(SettingsFile *file, SettingsFileEachCallback cb, void *context) {
  return S_SUCCESS;
}

int settings_file_get_len(SettingsFile *file, const void *key, size_t key_len) {
  return 0;
}

status_t settings_file_delete(SettingsFile *file, const void *key, size_t key_len) {
  return S_SUCCESS;
}

void settings_file_close(SettingsFile *file) {}
