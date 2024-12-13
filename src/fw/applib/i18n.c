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

#include "syscall/syscall.h"
#include "process_state/app_state/app_state.h"
#include "services/common/i18n/i18n.h"

const char *app_get_system_locale(void) {
  LocaleInfo *info = app_state_get_locale_info();
  sys_i18n_get_locale(info->sys_locale);
  return info->sys_locale;
}

void app_i18n_get(const char *locale, const char *string, char *buffer, size_t length) {
  const char *system_locale = app_get_system_locale();
  if (strncmp(locale, system_locale, ISO_LOCALE_LENGTH) != 0) {
    strncpy(buffer, string, length);
    buffer[length - 1] = '\0';
  } else {
    sys_i18n_get_with_buffer(string, buffer, length);
  }
}

