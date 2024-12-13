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

#include "applib/ui/recognizer/recognizer.h"

#include <stdbool.h>
#include <stdint.h>

#define NEW_RECOGNIZER(r) \
  Recognizer *r __attribute__ ((__cleanup__(test_recognizer_destroy)))

typedef struct TestImplData {
  int test;
  bool *destroyed;
  bool *cancelled;
  bool *reset;
  bool *handled;
  bool *updated;
  bool *failed;
  TouchEvent *last_touch_event;
  RecognizerState *new_state;
} TestImplData;

Recognizer *test_recognizer_create(TestImplData *test_impl_data, void *user_data);

void test_recognizer_destroy(Recognizer **recognizer);

void test_recognizer_enable_on_destroy(void);
