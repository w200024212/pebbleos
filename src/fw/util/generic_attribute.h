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

#include "util/attributes.h"

#include <inttypes.h>
#include <stddef.h>

typedef struct PACKED GenericAttribute {
  uint8_t id;
  uint16_t length;
  uint8_t data[];
} GenericAttribute;

typedef struct PACKED GenericAttributeList {
  uint8_t num_attributes;
  GenericAttribute attributes[];
} GenericAttributeList;

GenericAttribute *generic_attribute_find_attribute(GenericAttributeList *attr_list, uint8_t id,
                                                   size_t size);

GenericAttribute *generic_attribute_add_attribute(GenericAttribute *attr, uint8_t id, void *data,
                                                  size_t size);
