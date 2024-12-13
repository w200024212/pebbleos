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

#include "rocky_res.h"

#include "process_management/process_manager.h"
#include "resource/resource_storage.h"
#include "rocky.h"

bool rocky_app_has_compatible_bytecode_res(ResAppNum app_num) {
  // we will iterate over each resource to detect any compatible JS byte code
  // if there's any, we can assume that there's also a resource with ID 1.
  const uint32_t entries = resource_storage_get_num_entries(app_num, 1);
  for (uint32_t entry_id = 1; entry_id <= entries; entry_id++) {
    // this buffer needs to be large enough to carry
    // RockySnapshotHeader + the relevant data JerryScript verifies
    uint8_t snapshot_start[sizeof(RockySnapshotHeader) + sizeof(uint64_t)];
    const size_t bytes_read = resource_load_byte_range_system(app_num, entry_id, 0,
                                                              snapshot_start,
                                                              sizeof(snapshot_start));
    if (rocky_is_snapshot(snapshot_start, bytes_read)) {
      return true;
    }
  }

  return false;
}

RockyResourceValidation rocky_app_validate_resources(const PebbleProcessMd *md) {
  if (!md || !md->is_rocky_app) {
    // it's not a rocky app, so it cannot have incompatible byte code
    return RockyResourceValidation_NotRocky;
  }
  const ResAppNum app_num = (ResAppNum)process_metadata_get_res_bank_num(md);
  if (app_num == (ResAppNum)SYSTEM_APP_BANK_ID) {
    // in case of the FW, we can assume that our JS is valid
    return RockyResourceValidation_Valid;
  }

  if (rocky_app_has_compatible_bytecode_res(app_num)) {
    return RockyResourceValidation_Valid;
  } else {
    return RockyResourceValidation_Invalid;
  }
}
