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

#include "resource_mapped.h"

#include "drivers/flash.h"
#include "system/passert.h"

#if CAPABILITY_HAS_MAPPABLE_FLASH
static uint32_t s_mapped_refcount_for_task[NumPebbleTask];

void resource_mapped_use(PebbleTask task) {
  // We keep track of the refcount per task so we can cleanup all resources for a task
  s_mapped_refcount_for_task[task]++;
  flash_use();
}

void resource_mapped_release(PebbleTask task) {
  PBL_ASSERTN(s_mapped_refcount_for_task[task] != 0);
  s_mapped_refcount_for_task[task]--;
  flash_release_many(1);
}

void resource_mapped_release_all(PebbleTask task) {
  flash_release_many(s_mapped_refcount_for_task[task]);
  s_mapped_refcount_for_task[task] = 0;
}
#endif
