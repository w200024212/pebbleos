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

///////////////////////////////////////
// Implements:
//   char *strcat(char *s1, const char *s2);
//   char *strncat(char *s1, const char *s2, size_t n);
///////////////////////////////////////
// Exports to apps:
//   strcat, strncat
///////////////////////////////////////
// Notes:
//   Tuned for code size.

#include <string.h>
#include <pblibc_private.h>

char *strcat(char * restrict s1, const char * restrict s2) {
  char *rc = s1;
  s1 += strlen(s1);
  strcpy(s1, s2);
  return rc;
}

char *strncat(char * restrict s1, const char * restrict s2, size_t n) {
  char * rc = s1;
  s1 += strlen(s1);

  size_t strn = strlen(s2);
  if (strn > n) {
    strn = n;
  }
  memcpy(s1, s2, strn);
  s1[strn] = '\0';
  return rc;
}
