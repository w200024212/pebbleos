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

#include "shell/system_theme.h"
#include "util/attributes.h"

#include <stdlib.h>

const char *WEAK system_theme_get_font_key(TextStyleFont font) {
  return NULL;
}

const char *WEAK system_theme_get_font_key_for_size(PreferredContentSize size,
                                                    TextStyleFont font) {
  return NULL;
}

GFont WEAK system_theme_get_font_for_default_size(TextStyleFont font) {
  return NULL;
}

PreferredContentSize WEAK system_theme_get_default_content_size_for_runtime_platform(void) {
  return PreferredContentSizeDefault;
}

PreferredContentSize WEAK system_theme_convert_host_content_size_to_runtime_platform(
    PreferredContentSize size) {
  return size;
}
