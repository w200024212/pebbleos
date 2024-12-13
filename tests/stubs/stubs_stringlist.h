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
#include "util/stringlist.h"

int WEAK string_list_add_string(StringList *list, size_t max_list_size, const char *str,
                                size_t max_str_size) {
  return 0;
}

size_t WEAK string_list_count(StringList *list) {
  return 0;
}

char * WEAK string_list_get_at(StringList *list, size_t index) {
  return NULL;
}
