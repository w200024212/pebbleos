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

#include "applib/ui/option_menu_window.h"

#include "applib/ui/ui.h"

typedef struct {
  OptionMenuCallbacks callbacks;
  void *context;
  const char **rows;
  uint16_t num_rows;
} SettingsOptionMenuData;

OptionMenu *settings_option_menu_create(
    const char *i18n_title_key, OptionMenuContentType content_type, int choice,
    const OptionMenuCallbacks *callbacks, uint16_t num_rows, bool icons_enabled, const char **rows,
    void *context);

OptionMenu *settings_option_menu_push(
    const char *i18n_title_key, OptionMenuContentType content_type, int choice,
    const OptionMenuCallbacks *callbacks, uint16_t num_rows, bool icons_enabled, const char **rows,
    void *context);

void *settings_option_menu_get_context(SettingsOptionMenuData *data);
