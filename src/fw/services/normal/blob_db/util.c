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

#include "util.h"

#include "kernel/pbl_malloc.h"

#include <stdlib.h>

void blob_db_util_free_dirty_list(BlobDBDirtyItem *dirty_list) {
  ListNode *head = &dirty_list->node;
  ListNode *cur;
  while (head) {
    cur = head;
    list_remove(cur, &head, NULL);
    kernel_free(cur);
  }
}
