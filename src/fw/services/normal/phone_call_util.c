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

#include "phone_call_util.h"

#include "kernel/pbl_malloc.h"
#include "services/common/i18n/i18n.h"

#include <string.h>

PebblePhoneCaller* phone_call_util_create_caller(const char *number, const char *name) {
  PebblePhoneCaller *caller = kernel_zalloc(sizeof(PebblePhoneCaller));
  if (!caller) {
    return NULL;
  }

  if ((!name || !strlen(name)) && (!number || !strlen(number))) {
    const char *i18n_name = i18n_get("Unknown", __FILE__);

    caller->name = kernel_malloc(strlen(i18n_name) + 1);
    if (caller->name) {
      strcpy(caller->name, i18n_name);
    }
    i18n_free(i18n_name, __FILE__);

    return caller;
  }

  if (number) {
    caller->number = kernel_malloc(strlen(number) + 1);
    if (caller->number) {
      strcpy(caller->number, number);
    }
  }
  if (name) {
    caller->name = kernel_malloc(strlen(name) + 1);
    if (caller->name) {
      strcpy(caller->name, name);
    }
  }

  return caller;
}

void phone_call_util_destroy_caller(PebblePhoneCaller *caller) {
  if (caller) {
    kernel_free(caller->number);
    kernel_free(caller->name);
    kernel_free(caller);
  }
}
