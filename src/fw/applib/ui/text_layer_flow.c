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

#include "text_layer_flow.h"
#include "scroll_layer.h"

static bool prv_is_container_layer(const Layer *layer) {
  return scroll_layer_is_instance(layer);
}

Layer *text_layer_find_first_paging_container(const TextLayer *text_layer) {
  Layer *layer = text_layer->layer.parent;
  while (layer) {
    if (prv_is_container_layer(layer)) {
      return layer;
    }
    layer = layer->parent;
  }
  return NULL;
}

bool text_layer_calc_text_flow_paging_values(const TextLayer *text_layer,
                                             GPoint *content_origin_on_screen,
                                             GRect *page_rect_on_screen) {
  if (text_layer == NULL || text_layer->layer.window == NULL || text_layer->layer.parent == NULL) {
    return false;
  }

  if (content_origin_on_screen) {
    *content_origin_on_screen = layer_convert_point_to_screen(&text_layer->layer, GPointZero);
  }

  if (page_rect_on_screen) {
    const Layer *container =
      text_layer_find_first_paging_container(text_layer) ?: &text_layer->layer;
    layer_get_global_frame(container, page_rect_on_screen);
    if (container == &text_layer->layer) {
      page_rect_on_screen->size.h = TEXT_LAYER_FLOW_DEFAULT_PAGING_HEIGHT;
    }
  }

  return true;
}
