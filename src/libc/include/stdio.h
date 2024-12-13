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

#define __need_size_t
#define __need_NULL
#include <stddef.h>

#define __need___va_list
#include <stdarg.h>

typedef struct {
} FILE;

// stdio.h isn't supposed to define va_list, so _need___va_list gives us __gnuc_va_list
// Let's define that to something less compiler-specific
#define  __VA_LIST __gnuc_va_list

int printf(const char *__restrict format, ...)
        __attribute__((format (printf, 1, 2)));
int sprintf(char * restrict str, const char * restrict format, ...)
        __attribute__((__format__(__printf__, 2, 3)));
int snprintf(char * restrict str, size_t size, const char * restrict format, ...)
        __attribute__((__format__(__printf__, 3, 4)));
int vsprintf(char * restrict str, const char * restrict format, __VA_LIST ap)
        __attribute__((__format__(__printf__, 2, 0)));
int vsnprintf(char * restrict str, size_t size, const char * restrict format, __VA_LIST ap)
        __attribute__((__format__(__printf__, 3, 0)));

#if !UNITTEST
#define sniprintf snprintf
#define vsniprintf vsnprintf
#endif
