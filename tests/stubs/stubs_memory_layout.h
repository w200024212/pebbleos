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

#include "kernel/memory_layout.h"

const MpuRegion* memory_layout_get_app_region(void) { return NULL; }
const MpuRegion* memory_layout_get_app_stack_guard_region(void) { return NULL; }

const MpuRegion* memory_layout_get_readonly_bss_region(void) { return NULL; }
const MpuRegion* memory_layout_get_microflash_region(void) { return NULL; }

const MpuRegion* memory_layout_get_worker_region(void) { return NULL; }
const MpuRegion* memory_layout_get_worker_stack_guard_region(void) { return NULL; }

const MpuRegion* memory_layout_get_kernel_main_stack_guard_region(void) { return NULL; }
const MpuRegion* memory_layout_get_kernel_bg_stack_guard_region(void) { return NULL; }

bool memory_layout_is_pointer_in_region(const MpuRegion *region, const void *ptr) { return false; }
bool memory_layout_is_buffer_in_region(const MpuRegion *region, const void *buf,
                                       size_t length) { return false; }
bool memory_layout_is_cstring_in_region(const MpuRegion *region, const char *str,
                                        size_t max_length) { return false; }
