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

#include "app_recognizers.h"

#include "process_state/app_state/app_state.h"

void app_recognizers_attach_recognizer(Recognizer *recognizer) {
  recognizer_add_to_list(recognizer, app_state_get_recognizer_list());
}

void app_recognizers_detach_recognizer(Recognizer *recognizer) {
  recognizer_remove_from_list(recognizer, app_state_get_recognizer_list());
}
