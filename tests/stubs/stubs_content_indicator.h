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

#include "applib/ui/content_indicator.h"

void content_indicator_init_buffer(ContentIndicatorsBuffer *content_indicators_buffer) {}

ContentIndicator *content_indicator_get_for_scroll_layer(ScrollLayer *scroll_layer) {
  return NULL;
}

ContentIndicator *content_indicator_get_or_create_for_scroll_layer(ScrollLayer *scroll_layer) {
  return NULL;
}

void content_indicator_destroy_for_scroll_layer(ScrollLayer *scroll_layer) {}

void content_indicator_set_content_available(ContentIndicator *content_indicator,
                                             ContentIndicatorDirection direction,
                                             bool available) {}
