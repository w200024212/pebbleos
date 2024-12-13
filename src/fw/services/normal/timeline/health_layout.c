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

#include "health_layout.h"
#include "timeline_layout.h"

#include "kernel/pbl_malloc.h"
#include "resource/resource_ids.auto.h"
#include "services/common/i18n/i18n.h"
#include "services/normal/activity/activity_insights.h"
#include "services/normal/activity/health_util.h"
#include "util/size.h"

#include <stdio.h>

#if !PLATFORM_TINTIN
//////////////////////////////////////////
//  Card Mode
//////////////////////////////////////////

#define CARD_MARGIN_TOP PBL_IF_RECT_ELSE(0, 5)
#define CARD_MARGIN_BOTTOM PBL_IF_RECT_ELSE(11, 0)

static GTextNode *prv_card_view_constructor(TimelineLayout *timeline_layout) {
  const LayoutNodeExtentConfig s_metrics_config = {
    .node.type = LayoutNodeType_TimelineMetrics,
    .offset.y = CARD_MARGIN_TOP,
    .margin.h = CARD_MARGIN_TOP + CARD_MARGIN_BOTTOM,
  };
  return layout_create_text_node_from_config(&timeline_layout->layout_layer,
                                             &s_metrics_config.node);
}

//////////////////////////////////////////
// LayoutLayer API
//////////////////////////////////////////

bool health_layout_verify(bool existing_attributes[]) {
  return existing_attributes[AttributeIdTitle];
}

LayoutLayer *health_layout_create(const LayoutLayerConfig *config) {
  HealthLayout *layout = task_zalloc_check(sizeof(HealthLayout));

  static const TimelineLayoutImpl s_timeline_layout_impl = {
    .attributes = { AttributeIdTitle, AttributeIdSubtitle },
    .default_colors = { { .argb = GColorBlackARGB8 },
                        { .argb = GColorWhiteARGB8 },
                        { .argb = GColorSunsetOrangeARGB8 } },
    .default_icon = TIMELINE_RESOURCE_ACTIVITY,
    .card_icon_align = PBL_IF_ROUND_ELSE(GAlignCenter, GAlignLeft),
    .card_icon_size = TimelineResourceSizeTiny,
    .card_view_constructor = prv_card_view_constructor,
  };

  timeline_layout_init((TimelineLayout *)layout, config, &s_timeline_layout_impl);

  return (LayoutLayer *)layout;
}
#endif
