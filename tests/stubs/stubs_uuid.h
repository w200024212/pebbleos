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

#include "util/uuid.h"


bool uuid_equal(const Uuid *uu1, const Uuid *uu2) {
  return false;
}

void uuid_generate(Uuid *uuid_out) {
}

bool uuid_is_system(const Uuid *uuid) {
  return false;
}

bool uuid_is_invalid(const Uuid *uuid) {
  return false;
}

void uuid_to_string(const Uuid *uuid, char *buffer) {

}
