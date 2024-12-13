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

#include "i18n.h"

#include "kernel/memory_layout.h"
#include "kernel/pebble_tasks.h"
#include "syscall/syscall_internal.h"
#include "system/logging.h"

DEFINE_SYSCALL(void, sys_i18n_get_locale, char *buf) {
  if (PRIVILEGE_WAS_ELEVATED) {
    if (pebble_task_get_current() == PebbleTask_Worker) {
      // not allowed from workers
      syscall_failed();
    }
  }

  strncpy(buf, i18n_get_locale(), ISO_LOCALE_LENGTH);
}

DEFINE_SYSCALL(void, sys_i18n_get_with_buffer, const char *string,
               char *buffer, size_t length) {
  if (PRIVILEGE_WAS_ELEVATED) {
    if (pebble_task_get_current() == PebbleTask_Worker) {
      // not allowed from workers
      syscall_failed();
    }
    if (!memory_layout_is_cstring_in_region(memory_layout_get_app_region(), string, 100) &&
        !memory_layout_is_cstring_in_region(memory_layout_get_microflash_region(), string, 100)) {
      PBL_LOG(LOG_LEVEL_ERROR, "Pointer %p not in app or microflash region", string);
      syscall_failed();
    }
    syscall_assert_userspace_buffer(buffer, length);
  }

  i18n_get_with_buffer(string, buffer, length);
}

DEFINE_SYSCALL(size_t, sys_i18n_get_length, const char *string) {
  if (PRIVILEGE_WAS_ELEVATED) {
    if (pebble_task_get_current() == PebbleTask_Worker) {
      // not allowed from workers
      syscall_failed();
    }
    if (!memory_layout_is_cstring_in_region(memory_layout_get_app_region(), string, 100) &&
        !memory_layout_is_cstring_in_region(memory_layout_get_microflash_region(), string, 100)) {
      PBL_LOG(LOG_LEVEL_ERROR, "Pointer %p not in app or microflash region", string);
      syscall_failed();
    }
  }

  return i18n_get_length(string);
}
