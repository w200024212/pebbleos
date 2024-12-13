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

#define __need_NULL
#include <stddef.h>

// We use newlib's order because why not and it'll make us more compatible.
#ifndef LC_ALL
# define LC_ALL      0
#endif
#ifndef LC_COLLATE
# define LC_COLLATE  1
#endif
#ifndef LC_CTYPE
# define LC_CTYPE    2
#endif
#ifndef LC_MONETARY
# define LC_MONETARY 3
#endif
#ifndef LC_NUMERIC
# define LC_NUMERIC  4
#endif
#ifndef LC_TIME
# define LC_TIME     5
#endif
#ifndef LC_MESSAGES
# define LC_MESSAGES 6
#endif

struct lconv {
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_p_sign_posn;
};

char *setlocale(int category, const char *locale);
