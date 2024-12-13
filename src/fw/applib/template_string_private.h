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

#include "applib/template_string.h"

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

typedef struct TemplateStringState {
  const char *position;
  char *output;
  size_t output_remaining;
  TemplateStringEvalConditions *eval_cond;
  const TemplateStringVars *vars;
  TemplateStringError *error;

  intmax_t filter_state;
  //! Set to true when the filter_state was set by `time_until`, false for `time_since`.
  bool time_was_until;
  bool filters_complete;
} TemplateStringState;
