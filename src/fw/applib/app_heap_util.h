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

//! @addtogroup Foundation
//! @{
//!   @addtogroup MemoryManagement Memory Management
//!   \brief Utility functions for managing an application's memory.
//!
//!   @{

//! Calculates the number of bytes of heap memory currently being used by the application.
//! @return The number of bytes on the heap currently being used.
size_t heap_bytes_used(void);

//! Calculates the number of bytes of heap memory \a not currently being used by the application.
//! @return The number of bytes on the heap not currently being used.
size_t heap_bytes_free(void);

//!   @} // end addtogroup MemoryManagement
//! @} // end addtogroup Foundation
