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

///////////////////////////////////////
// Notes:
//   This is entirely non-portable. It will need to be rewritten if we stop using ARM.
//   Unfortunately, there is no portable way to define these.
//   This means unit tests can't use our setjmp/longjmp either.

#pragma once

#if __arm__
// On ARM at least, GPRs are longs
// This still holds on A64.
struct __jmp_buf_struct {
  long r4, r5, r6, r7, r8, r9, sl, fp, sp, lr;
// Using real FPU
#if defined(__VFP_FP__) && !defined(__SOFTFP__)
  // FPU registers are still 32bit on A64 though, so they're ints
  int s[16]; /* s16~s31 */
  int fpscr;
#endif
};
typedef struct __jmp_buf_struct jmp_buf[1];

int setjmp(jmp_buf env);
void longjmp(jmp_buf buf, int value);
#else
// other implementations either use system setjmp or don't have it.
# include_next <setjmp.h>
#endif
