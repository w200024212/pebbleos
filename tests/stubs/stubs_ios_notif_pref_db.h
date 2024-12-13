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

#include "services/normal/blob_db/api.h"
#include "services/normal/blob_db/ios_notif_pref_db.h"
#include "services/normal/timeline/item.h"

iOSNotifPrefs* ios_notif_pref_db_get_prefs(const uint8_t *app_id, int length) {
  return NULL;
}

void ios_notif_pref_db_free_prefs(iOSNotifPrefs *prefs) {
  return;
}

status_t ios_notif_pref_db_store_prefs(const uint8_t *app_id, int length, AttributeList *attr_list,
                                       TimelineItemActionGroup *action_group) {
  return S_SUCCESS;
}

void ios_notif_pref_db_init(void) {
  return;
}

status_t ios_notif_pref_db_insert(const uint8_t *key, int key_len, const uint8_t *val,
                                  int val_len) {
  return S_SUCCESS;
}

int ios_notif_pref_db_get_len(const uint8_t *key, int key_len) {
  return 1;
}

status_t ios_notif_pref_db_read(const uint8_t *key, int key_len, uint8_t *val_out,
                                int val_out_len) {
  return S_SUCCESS;
}

status_t ios_notif_pref_db_delete(const uint8_t *key, int key_len) {
  return S_SUCCESS;
}

status_t ios_notif_pref_db_flush(void) {
  return S_SUCCESS;
}

status_t ios_notif_pref_db_is_dirty(bool *is_dirty_out) {
  *is_dirty_out = true;
  return S_SUCCESS;
}

BlobDBDirtyItem* ios_notif_pref_db_get_dirty_list(void) {
  return NULL;
}

status_t ios_notif_pref_db_mark_synced(const uint8_t *key, int key_len) {
  return S_SUCCESS;
}
