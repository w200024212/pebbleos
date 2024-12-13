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

#include "date.h"

bool date_util_is_leap_year(int year) {
  return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

int date_util_get_max_days_in_month(int month, bool is_leap_year) {
  int days;

  switch (month) {
    case 4: //April
    case 6: //June
    case 9: //September
    case 11: //November
    {
      days = 30;
      break;
    }
    case 2: // February
    {
      days = is_leap_year ? 29 : 28;
      break;
    }
    default:
    {
      // Jan, March, May, July, August, October, December
      days = 31;
      break;
    }
  }
  return days;
}
