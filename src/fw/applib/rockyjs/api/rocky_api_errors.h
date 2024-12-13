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

#include "jerry-api.h"

// Raise TypeError: Not enough arguments
jerry_value_t rocky_error_arguments_missing(void);

jerry_value_t rocky_error_argument_invalid_at_index(uint32_t arg_idx, const char *error_msg);

jerry_value_t rocky_error_argument_invalid(const char *msg);

jerry_value_t rocky_error_oom(const char *hint);

jerry_value_t rocky_error_unexpected_type(uint32_t arg_idx, const char *expected_type_name);

// Print error type & msg
void rocky_error_print(jerry_value_t error_val);
