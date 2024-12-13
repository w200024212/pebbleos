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

#include "generic_attribute.h"

#include "system/logging.h"

GenericAttribute *generic_attribute_find_attribute(GenericAttributeList *attr_list, uint8_t id,
                                                   size_t size) {
  uint8_t *cursor = (uint8_t *)(attr_list->attributes);
  uint8_t *end = (uint8_t *)attr_list + size;
  for (unsigned int i = 0; i < attr_list->num_attributes; i++) {
    GenericAttribute *attribute = (GenericAttribute *)cursor;

    // Check that we do not read past the end of the buffer
    if ((cursor + sizeof(GenericAttribute) >= end) || (attribute->data + attribute->length > end)) {
      PBL_LOG(LOG_LEVEL_WARNING, "Attribute list is invalid");
      return NULL;
    }

    if (attribute->id == id) {
      return attribute;
    }
    cursor += sizeof(GenericAttribute) + attribute->length;
  }
  return NULL;
}

GenericAttribute *generic_attribute_add_attribute(GenericAttribute *attr, uint8_t id, void *data,
                                                  size_t size) {
  *attr = (GenericAttribute) {
    .id = id,
    .length = size,
  };
  memcpy(attr->data, data, size);

  uint8_t *cursor = (uint8_t *)attr;
  cursor += sizeof(GenericAttribute) + size;
  return (GenericAttribute *)cursor;
}
