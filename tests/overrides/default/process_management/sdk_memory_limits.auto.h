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

//! Memory limits for SDK applications
//!
//! These macros describe the memory limits imposed on SDK applications
//! based on the major SDK version they were compiled against. The
//! limits vary depending on both the SDK version and the platform.
//!
//! The APP_RAM_nX_SIZE macros describe the total amount of memory that
//! an SDK app can use directly for stack, heap, text, data and bss.

#pragma once

#include <stddef.h>

#define APP_RAM_SYSTEM_SIZE ((size_t)65536)
#define APP_RAM_2X_SIZE ((size_t)23900)
#define APP_RAM_3X_SIZE ((size_t)65536)
#define APP_RAM_4X_SIZE ((size_t)65536)
