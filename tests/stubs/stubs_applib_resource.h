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

bool applib_resource_track_mmapped(const void *bytes) {
  return false;
}

bool applib_resource_is_mmapped(const void *bytes) {
  return false;
}

bool applib_resource_munmap(const void *bytes) {
  return false;
}

bool applib_resource_munmap_all() {
  return false;
}

void applib_resource_munmap_or_free(void *bytes) {
  free(bytes);
}

// this is just a stub, if you need proper resource handling
// link against fake_applib_resource.c in your test
void *applib_resource_mmap_or_load(ResAppNum app_num, uint32_t resource_id,
                                   size_t offset, size_t num_bytes, bool used_aligned) {
  return NULL;
}
