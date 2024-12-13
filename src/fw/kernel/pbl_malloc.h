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

#include <inttypes.h>
#include <stddef.h>

//! @file pbl_malloc.h
//!
//! In the firmware, we actually have multiple heaps that clients can use to malloc/free on.
//! The kernel heap is located in protected memory and is used by the kernel itself. The app
//! heap is located inside the app region and is reset between each app.

typedef struct Heap Heap;

Heap *task_heap_get_for_current_task(void);

// task_* functions map to app_* or kernel_* based on which task we're calling it on.
void *task_malloc(size_t bytes);
#if defined(MALLOC_INSTRUMENTATION)
void *task_malloc_with_pc(size_t bytes, uintptr_t client_pc);
#endif
void *task_malloc_check(size_t bytes);
void *task_realloc(void *ptr, size_t size);
void *task_zalloc(size_t size);
void *task_zalloc_check(size_t size);
void *task_calloc(size_t count, size_t size);
void *task_calloc_check(size_t count, size_t size);
void task_free(void *ptr);
#if defined(MALLOC_INSTRUMENTATION)
void task_free_with_pc(void *ptr, uintptr_t client_pc);
#endif
char* task_strdup(const char* s);

void *app_malloc(size_t bytes);
void *app_malloc_check(size_t bytes);
void *app_realloc(void *ptr, size_t bytes);
void *app_zalloc(size_t size);
void *app_zalloc_check(size_t size);
void *app_calloc(size_t count, size_t size);
void *app_calloc_check(size_t count, size_t size);
void app_free(void *ptr);
char* app_strdup(const char* s);

void *kernel_malloc(size_t bytes);
void *kernel_malloc_check(size_t bytes);
void *kernel_realloc(void *ptr, size_t bytes);
void *kernel_zalloc(size_t size);
void *kernel_zalloc_check(size_t size);
void *kernel_calloc(size_t count, size_t size);
void *kernel_calloc_check(size_t count, size_t size);
void kernel_free(void *ptr);
char *kernel_strdup(const char *s);
char *kernel_strdup_check(const char *s);
