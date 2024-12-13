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

#include "util/array.h"

#include "system/passert.h"

#include <stdlib.h>

void array_remove_nulls(void **array, size_t *num) {
  PBL_ASSERTN(array && num);
  size_t i = 0;
  while (i < *num) {
    if (array[i] == NULL) {
      for (size_t j = i + 1; j < *num; j++) {
        array[j-1] = array[j];
      }
      (*num)--;
    } else {
      i++;
    }
  }
}
