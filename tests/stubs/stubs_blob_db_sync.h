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

#include "services/normal/blob_db/sync.h"

status_t blob_db_sync_db(BlobDBId db_id) {
  return S_SUCCESS;
}

status_t blob_db_sync_record(BlobDBId db_id, const void *key, int key_len, time_t last_updated) {
  return S_SUCCESS;
}

BlobDBSyncSession *blob_db_sync_get_session_for_id(BlobDBId db_id) {
  return NULL;
}

BlobDBSyncSession *blob_db_sync_get_session_for_token(BlobDBToken token) {
  return NULL;
}

void blob_db_sync_next(BlobDBSyncSession *session) {
  return;
}

void blob_db_sync_cancel(BlobDBSyncSession *session) {
  return;
}
