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

#include "services/common/i18n/i18n.h"
#include <locale.h>

typedef struct {
  char sys_locale[ISO_LOCALE_LENGTH];
  char app_locale_time[ISO_LOCALE_LENGTH];
  char app_locale_strings[ISO_LOCALE_LENGTH];
} LocaleInfo;

void locale_init_app_locale(LocaleInfo *info);

char *pbl_setlocale(int category, const char *locale);

struct _reent;

struct lconv *pbl_localeconv_r(struct _reent *data);

