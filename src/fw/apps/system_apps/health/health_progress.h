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

#include "applib/ui/ui.h"

#define HEALTH_PROGRESS_BAR_MAX_VALUE 0xfff

typedef int32_t HealthProgressBarValue;

typedef enum HealthProgressSegmentType {
  HealthProgressSegmentType_Horizontal,
  HealthProgressSegmentType_Vertical,
  HealthProgressSegmentType_Corner,
  HealthProgressSegmentTypeCount,
} HealthProgressSegmentType;

typedef struct HealthProgressSegment {
  HealthProgressSegmentType type;
  // The amount of the total progress bar that this segment occupies.
  // Summing this value over all segments should total HEALTH_PROGRESS_BAR_MAX_VALUE
  int amount_of_total;
  int mark_width;
  GPoint points[4];
} HealthProgressSegment;

typedef struct HealthProgressBar {
  int num_segments;
  HealthProgressSegment *segments;
} HealthProgressBar;


void health_progress_bar_fill(GContext *ctx, HealthProgressBar *progress_bar, GColor color,
                              HealthProgressBarValue start, HealthProgressBarValue end);

void health_progress_bar_mark(GContext *ctx, HealthProgressBar *progress_bar, GColor color,
                              HealthProgressBarValue value_to_mark);

void health_progress_bar_outline(GContext *ctx, HealthProgressBar *progress_bar, GColor color);
