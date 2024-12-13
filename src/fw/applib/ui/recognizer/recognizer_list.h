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

#include "util/list.h"

#include <stdbool.h>
#include <stdint.h>

struct Recognizer;

typedef struct RecognizerList {
  ListNode *node;
} RecognizerList;

//! Recognizer iterator callback function
//! @return true if iteration should continue after returning
typedef bool (*RecognizerListIteratorCb)(struct Recognizer *recognizer, void *context);

//! Initialize recognizer list
void recognizer_list_init(RecognizerList *list);

//! Iterate over a recognizer list. It is safe to remove a recognizer from the list (and destroy it)
//! from within the iterator callback
//! @param list \ref RecognizerList to iterate over
//! @param iter_cb iterator callback
//! @param context optional iterator context
//! @return true if iteration through all recognizers in the list completed, false otherwise
bool recognizer_list_iterate(RecognizerList *list, RecognizerListIteratorCb iter_cb, void *context);
