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

#include <stddef.h>

//! @file cpu_cache.h
//! @addtogroup Foundation
//! @{
//!   @addtogroup MemoryManagement Memory Management
//!   \brief Utility functions for managing an application's memory.
//!
//!   @{

//! Flushes the data cache and invalidates the instruction cache for the given region of memory,
//! if necessary. This is only required when your app is loading or modifying code in memory and
//! intends to execute it. On some platforms, code executed may be cached internally to improve
//! performance. After writing to memory, but before executing, this function must be called in
//! order to avoid undefined behavior. On platforms without caching, this performs no operation.
//! @param start The beginning of the buffer to flush
//! @param size How many bytes to flush
void memory_cache_flush(void *start, size_t size);

//!   @} // end addtogroup MemoryManagement
//! @} // end addtogroup Foundation
