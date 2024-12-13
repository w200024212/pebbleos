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

#include "drivers/mpu.h"

// Everything but NULL + 256
const MpuRegion s_fake_app_region = { .region_num = 9, .enabled = true, .base_address = 256,
  .size = 0xFFFFFFFF - (1 << 8), .priv_read = true, .priv_write = true, .user_read = true, .user_write = true };

const MpuRegion* memory_layout_get_app_region(void) {
  return &s_fake_app_region;
}

bool memory_layout_is_pointer_in_region(const MpuRegion *region, const void *ptr) {
  uintptr_t p = (uintptr_t) ptr;
  return (p >= region->base_address && p < (region->base_address + region->size));
}

bool memory_layout_is_buffer_in_region(const MpuRegion *region, const void *buf, size_t length) {
  return memory_layout_is_pointer_in_region(region, buf) && memory_layout_is_pointer_in_region(region, buf + length);
}
