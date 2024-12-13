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

#include "sync_util.h"

#include "kernel/pbl_malloc.h"
#include "system/logging.h"

// Caution: CommonTimelineItemHeader .flags & .status are stored inverted and not auto-restored
// by the underlying db API. If .flags or .status is used from a CommonTimelineItemHeader below,
// be very careful


bool sync_util_is_dirty_cb(SettingsFile *file, SettingsRecordInfo *info, void *context) {
  // If there is a single dirty record, update the out bool to dirty and stop iterating
  if (info->dirty) {
    *((bool *)context) = true;
    return false;
  }

  return true;
}

bool sync_util_build_dirty_list_cb(SettingsFile *file, SettingsRecordInfo *info, void *context) {
  if (info->dirty) {
    BlobDBDirtyItem *dirty_list = *(BlobDBDirtyItem **)context;

    BlobDBDirtyItem *new_node = kernel_zalloc(sizeof(BlobDBDirtyItem) + info->key_len);
    if (!new_node) {
      PBL_LOG(LOG_LEVEL_WARNING, "Ran out of memory while building a dirty list");
      return false;
    }

    new_node->last_updated = info->last_modified;
    new_node->key_len = info->key_len;
    info->get_key(file, new_node->key, new_node->key_len);

    *(BlobDBDirtyItem **)context =
        (BlobDBDirtyItem *)list_prepend((ListNode *) dirty_list, (ListNode *)new_node);
  }

  return true;
}
