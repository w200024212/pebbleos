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

#include "system/status_codes.h"
#include "services/normal/timeline/item.h"

///////////////////////////////////////////
// BlobDB Boilerplate (see blob_db/api.h)
///////////////////////////////////////////

void notif_db_init(void);

status_t notif_db_insert(const uint8_t *key, int key_len, const uint8_t *val, int val_len);

int notif_db_get_len(const uint8_t *key, int key_len);

status_t notif_db_read(const uint8_t *key, int key_len, uint8_t *val_out, int val_out_len);

status_t notif_db_delete(const uint8_t *key, int key_len);

status_t notif_db_flush(void);
