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

#include "attribute.h"
#include "timeline_resources.h"

typedef struct MetricGroup {
  StringList *names;
  StringList *values;
  Uint32List *icons;
  int num_items;
  int max_num_items;
  size_t max_item_string_size;
} MetricGroup;

//! Create a metric group
//! @param max_num_items max number of items able to be added to the group
//! @param max_item_string_size max length of any string in the group, name and value
//! @return newly allocated MetricGroup
MetricGroup *metric_group_create(int max_num_items, size_t max_item_string_size);

//! Destroy a metric group
//! @param metric_group MetricGroup to destroy
void metric_group_destroy(MetricGroup *metric_group);

//! Adds an item to a metric group
//! @param metric_group MetricGroup to add an item to
//! @param name_i18n i18n key of the name string
//! @param value value field string
//! @param icon TimelineResourceId icon id
//! @param i18n_owner i18n owner to use
//! @return true if the item was added, false otherwise
bool metric_group_add_item(MetricGroup *metric_group, const char *name_i18n, const char *value,
                           TimelineResourceId icon, void *i18n_owner);
