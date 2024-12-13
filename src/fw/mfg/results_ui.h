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

#include "applib/ui/window.h"
#include "applib/ui/text_layer.h"
#include "mfg/mfg_info.h"

typedef void (*MfgResultsCallback)(void);

typedef struct {
  MfgTest test;

  TextLayer pass_text_layer;
  TextLayer fail_text_layer;

  MfgResultsCallback results_cb;
} MfgResultsUI;

void mfg_results_ui_init(MfgResultsUI *results_ui, MfgTest test, Window *window);
void mfg_results_ui_set_callback(MfgResultsUI *ui, MfgResultsCallback cb);
