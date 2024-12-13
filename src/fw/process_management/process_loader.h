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

#include "kernel/pebble_tasks.h"

#include <stdint.h>
#include <stdbool.h>

typedef struct MemorySegment MemorySegment;
typedef struct PebbleProcessMd PebbleProcessMd;

//! Load the process image specified by app_md into memory.
//!
//! The memory that the process image is loaded into is split from the
//! destination memory segment. The destination memory segment must
//! already be zeroed out.
//!
//! Only the process' text, data and bss are loaded and split from the
//! memory segment. It is the caller's responsibility to set up the
//! process stack and heap.
//!
//! @return pointer to process's entry point function, or NULL if the
//!     process loading failed.
void * process_loader_load(const PebbleProcessMd *app_md, PebbleTask task,
                           MemorySegment *destination);
