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

// NOTE: This file is uses as an -include file when compiling each jerry-core source file, so
// be careful what you add here!

#define JERRY_CONTEXT(field) (rocky_runtime_context_get()->jerry_global_context.field)
#define JERRY_HEAP_CONTEXT(field) (rocky_runtime_context_get()->jerry_global_heap.field)
#define JERRY_HASH_TABLE_CONTEXT(field) (rocky_runtime_context_get()->jerry_global_hash_table.field)

#include "jcontext.h"

typedef struct RockyRuntimeContext {
  jerry_context_t jerry_global_context;
  jmem_heap_t jerry_global_heap;
#ifndef CONFIG_ECMA_LCACHE_DISABLE
  jerry_hash_table_t jerry_global_hash_table;
#endif
} RockyRuntimeContext;

_Static_assert(
    ((offsetof(RockyRuntimeContext, jerry_global_heap) +
      offsetof(jmem_heap_t, area)) % JMEM_ALIGNMENT) == 0,
    "jerry_global_heap.area must be aligned to JMEM_ALIGNMENT!");

extern RockyRuntimeContext * rocky_runtime_context_get(void);
