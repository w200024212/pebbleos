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

#include "mcu/cache.h"

void icache_enable(void) {}
void icache_disable(void) {}
void icache_invalidate_all(void) {}

void dcache_enable(void) {}
void dcache_disable(void) {}

void dcache_flush_all(void) {}
void dcache_invalidate_all(void) {}
void dcache_flush_invalidate_all(void) {}

void dcache_flush(const void *addr, size_t size) {}
void dcache_invalidate(void *addr, size_t size) {}
void dcache_flush_invalidate(const void *addr, size_t size) {}

uint32_t dcache_alignment_mask_minimum(uint32_t min) { return min - 1; }
