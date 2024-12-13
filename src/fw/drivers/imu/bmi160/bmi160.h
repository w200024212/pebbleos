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

#include <stdbool.h>

typedef enum {
  BMI160_Accel_Mode_Suspend = 0b00,
  BMI160_Accel_Mode_Normal = 0b01,
  BMI160_Accel_Mode_Low = 0b10,
} BMI160AccelPowerMode;

typedef enum {
  BMI160_Gyro_Mode_Suspend = 0b00,
  BMI160_Gyro_Mode_Normal = 0b01,
  BMI160_Gyro_Mode_FastStartup = 0b11
} BMI160GyroPowerMode;

void bmi160_init(void);
bool bmi160_query_whoami(void);
void bmi160_set_accel_power_mode(BMI160AccelPowerMode mode);
void bmi160_set_gyro_power_mode(BMI160GyroPowerMode mode);
