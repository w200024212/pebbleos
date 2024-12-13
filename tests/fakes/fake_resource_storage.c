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

#include "resource/resource_storage_flash.h"
#include "resource/resource_storage_impl.h"
#include "resource/resource.h"

#include <stdio.h>
#include <inttypes.h>

#include "flash_region/flash_region.h"
#include "util/string.h"

void resource_storage_get_file_name(char *name, size_t buf_length, ResAppNum resource_bank) {
  concat_str_int("res_bank", resource_bank, name, buf_length);
}

void resource_storage_clear(ResAppNum app_num) {
  return;
}

const SystemResourceBank * resource_storage_flash_get_unused_bank(void) {
  static const SystemResourceBank unused_bank = {
    .begin = FLASH_REGION_SYSTEM_RESOURCES_BANK_1_BEGIN,
    .end = FLASH_REGION_SYSTEM_RESOURCES_BANK_1_END,
  };
  return &unused_bank;
}
