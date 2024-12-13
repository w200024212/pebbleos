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

#include <stdlib.h>

static bool s_is_seeded = false;

bool rng_rand(uint32_t *rand_out) {
  if (!s_is_seeded) {
    srand(0); // Seed with constant, to make unit tests less random :)
    s_is_seeded = true;
  }
  *rand_out = rand();
  return true;
}
