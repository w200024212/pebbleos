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

#include "applib/pbl_std/locale.h"

#include <time.h>

struct tm *app_state_get_gmtime_tm(void);
struct tm *app_state_get_localtime_tm(void);
char *app_state_get_localtime_zone(void);

LocaleInfo *app_state_get_locale_info(void);

typedef int AppStateInitParams;
typedef struct {char _unused;} TextRenderState;
