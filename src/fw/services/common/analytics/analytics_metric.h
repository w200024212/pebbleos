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

#include <stdint.h>
#include <stdbool.h>

#include "analytics_metric_table.h"

typedef enum {
  ANALYTICS_METRIC_KIND_DEVICE,
  ANALYTICS_METRIC_KIND_APP,
  ANALYTICS_METRIC_KIND_MARKER,
  ANALYTICS_METRIC_KIND_UNKNOWN,
} AnalyticsMetricKind;

typedef enum {
  ANALYTICS_METRIC_ELEMENT_TYPE_NIL,
  ANALYTICS_METRIC_ELEMENT_TYPE_UINT8,
  ANALYTICS_METRIC_ELEMENT_TYPE_UINT16,
  ANALYTICS_METRIC_ELEMENT_TYPE_UINT32,
  ANALYTICS_METRIC_ELEMENT_TYPE_INT8,
  ANALYTICS_METRIC_ELEMENT_TYPE_INT16,
  ANALYTICS_METRIC_ELEMENT_TYPE_INT32,
} AnalyticsMetricElementType;

void analytics_metric_init(void);

AnalyticsMetricElementType analytics_metric_element_type(AnalyticsMetric metric);

uint32_t analytics_metric_num_elements(AnalyticsMetric metric);
uint32_t analytics_metric_element_size(AnalyticsMetric metric);
uint32_t analytics_metric_size(AnalyticsMetric metric);

bool analytics_metric_is_array(AnalyticsMetric metric);
bool analytics_metric_is_unsigned(AnalyticsMetric metric);

uint32_t analytics_metric_offset(AnalyticsMetric metric);

AnalyticsMetricKind analytics_metric_kind(AnalyticsMetric metric);
