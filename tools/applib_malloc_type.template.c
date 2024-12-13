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

// ${name}
///////////////////////////////////////////

#if (${check_size} && ${min_sdk} <= 2 && ${size_2x} > 0)
_Static_assert(sizeof(${name}) <= ${size_2x}, "<${name}> is too large for 2.x");
#endif

#if (${check_size} && ${size_3x} > 0)
_Static_assert(sizeof(${name}) <= ${size_3x}, "<${name}> is too large for 3.x");
_Static_assert(sizeof(${name}) + ${total_3x_padding} == ${size_3x},
               "<${name}> is incorrectly padded for 3.x, "
               "total padding: ${total_3x_padding} total size: ${size_3x}");
#endif

void *_applib_type_malloc_${name}(void) {
#if defined(MALLOC_INSTRUMENTATION)
  register uintptr_t lr __asm("lr");
  const uintptr_t saved_lr = lr;
#else
  const uintptr_t saved_lr = 0;
#endif
  return prv_malloc(prv_find_size(ApplibType_${name}), saved_lr);
}

void *_applib_type_zalloc_${name}(void) {
#if defined(MALLOC_INSTRUMENTATION)
  register uintptr_t lr __asm("lr");
  const uintptr_t saved_lr = lr;
#else
  const uintptr_t saved_lr = 0;
#endif
  return prv_zalloc(prv_find_size(ApplibType_${name}), saved_lr);
}

size_t _applib_type_size_${name}(void) {
  return prv_find_size(ApplibType_${name});
}
