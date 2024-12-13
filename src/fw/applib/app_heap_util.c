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

#include "app_heap_util.h"
#include "process_state/app_state/app_state.h"
#include "process_state/worker_state/worker_state.h"
#include "kernel/pebble_tasks.h"
#include "system/passert.h"
#include "util/heap.h"

static Heap* get_task_heap(void) {
  PebbleTask task = pebble_task_get_current();
  Heap *heap = NULL;

  if (task == PebbleTask_App) {
    heap = app_state_get_heap();
  } else if (task == PebbleTask_Worker) {
    heap = worker_state_get_heap();
  } else {
    WTF;
  }

  return heap;
}

size_t heap_bytes_used(void) {
  Heap *heap = get_task_heap();
  return heap->current_size;
}

size_t heap_bytes_free(void) {
  Heap *heap = get_task_heap();
  return heap_size(heap) - heap->current_size;
}
