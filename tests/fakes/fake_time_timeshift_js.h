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

#ifndef EMSCRIPTEN
#error "Expecting emscripten build!"
#endif

#include <emscripten/emscripten.h>

static void prv_check_is_timeshift_loaded(void) {
  EM_ASM(
    if (Module.setTime === undefined || Module.setTimezoneOffset === undefined) {
      throw new Error('timeshift.js not loaded?');
    }
  );
}

uint16_t time_ms(time_t *tloc, uint16_t *out_ms) {
  EM_ASM(throw new Error('NYI'));
  return 0;
}

int32_t time_get_gmtoffset(void) {
  EM_ASM(throw new Error('NYI'));
  return 0;
}

int32_t time_get_dstoffset(void) {
  EM_ASM(throw new Error('NYI'));
  return 0;
}

bool time_get_isdst(time_t utc_time) {
  EM_ASM(throw new Error('NYI'));
  return false;
}

time_t time_utc_to_local(time_t utc_time) {
  EM_ASM(throw new Error('NYI'));
  return 0;
}

time_t time_local_to_utc(time_t local_time) {
  EM_ASM(throw new Error('NYI'));
  return 0;
}

void fake_time_init(time_t initial_time, uint16_t initial_ms) {
  prv_check_is_timeshift_loaded();
  EM_ASM_INT({
    Module.setTimezoneOffset(0);
    Module.setTime($0 * 1000 + $1);
  }, initial_time, initial_ms);
}

void fake_time_set_dst(int32_t offset, int32_t start, int32_t stop) {
  EM_ASM(throw new Error('NYI'));
}

void fake_time_set_gmtoff(int32_t gmtoff) {
  EM_ASM(throw new Error('NYI'));
}
