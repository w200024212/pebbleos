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

#include "services/normal/blob_db/watch_app_prefs_db.h"

SerializedSendTextPrefs *watch_app_prefs_get_send_text(void);

///////////////////////////////////////////
// BlobDB Boilerplate (see blob_db/api.h)
///////////////////////////////////////////

void watch_app_prefs_db_init(void) {
}

status_t watch_app_prefs_db_insert(const uint8_t *key, int key_len, const uint8_t *val,
                                   int val_len) {
  return S_SUCCESS;
}

int watch_app_prefs_db_get_len(const uint8_t *key, int key_len) {
  return 0;
}

status_t watch_app_prefs_db_read(const uint8_t *key, int key_len, uint8_t *val_out,
                                 int val_out_len) {
  return S_SUCCESS;
}

status_t watch_app_prefs_db_delete(const uint8_t *key, int key_len) {
  return S_SUCCESS;
}

status_t watch_app_prefs_db_flush(void) {
  return S_SUCCESS;
}
