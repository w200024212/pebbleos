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

#include <stdint.h>
#include <stdbool.h>

#include "services/normal/blob_db/api.h"

#include "system/status_codes.h"

void test_db_init(void);

status_t test_db_insert(const uint8_t *key, int key_len, const uint8_t *val, int val_len);

int test_db_get_len(const uint8_t *key, int key_len);

status_t test_db_read(const uint8_t *key, int key_len, uint8_t *val_out, int val_out_len);

status_t test_db_delete(const uint8_t *key, int key_len);

status_t test_db_flush(void);

status_t test_db_is_dirty(bool *is_dirty_out);

BlobDBDirtyItem *test_db_get_dirty_list(void);

status_t test_db_mark_synced(uint8_t *key, int key_len);
