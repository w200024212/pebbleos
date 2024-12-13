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

#include "system/status_codes.h"
#include "util/list.h"

typedef enum {
  RamStorageFlagDirty = 1 << 0,
} RamStorageFlag;

typedef struct {
  ListNode node;
  uint8_t flags;
  uint8_t *key;
  int key_len;
  uint8_t *val;
  int val_len;
} RamStorageEntry;

typedef struct {
  RamStorageEntry *entries;
} RamStorage;

RamStorage ram_storage_create(void);

status_t ram_storage_insert(RamStorage *storage,
    const uint8_t *key, int key_len, const uint8_t *val, int val_len);

int ram_storage_get_len(RamStorage *storage,
    const uint8_t *key, int key_len);

status_t ram_storage_read(RamStorage *storage,
    const uint8_t *key, int key_len, uint8_t *val_out, int val_len);

status_t ram_storage_delete(RamStorage *storage,
    const uint8_t *key, int key_len);

status_t ram_storage_flush(RamStorage *storage);

typedef bool (RamStorageEachCb)(RamStorageEntry *entry, void *context);

status_t ram_storage_each(RamStorage *storage, RamStorageEachCb cb, void *context);

status_t ram_storage_is_dirty(RamStorage *storage, bool *is_dirty_out);

status_t ram_storage_mark_synced(RamStorage *storage, uint8_t *key, int key_len);
