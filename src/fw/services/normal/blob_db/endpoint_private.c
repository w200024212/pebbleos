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

#include "endpoint_private.h"

#include <stdbool.h>

extern void blob_db_set_accepting_messages(bool enabled);
extern void blob_db2_set_accepting_messages(bool enabled);

void blob_db_enabled(bool enabled) {
  blob_db_set_accepting_messages(enabled);
  blob_db2_set_accepting_messages(enabled);
}

const uint8_t *endpoint_private_read_token_db_id(const uint8_t *iter, BlobDBToken *out_token,
                                                 BlobDBId *out_db_id) {
  // read token
  *out_token = *(BlobDBToken*)iter;
  iter += sizeof(BlobDBToken);
  // read database id
  *out_db_id = *iter;
  iter += sizeof(BlobDBId);

  return iter;
}
