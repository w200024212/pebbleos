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

#include "drivers/imu.h"
#include "drivers/imu/mag3110/mag3110.h"
#include "drivers/mag.h"
#include "drivers/qemu/qemu_accel.h"

void imu_init(void) {
  qemu_accel_init();
#if CAPABILITY_HAS_MAGNETOMETER
  mag3110_init();
#endif
}

void imu_power_up(void) {
}

void imu_power_down(void) {
}

bool gyro_run_selftest(void) {
  return true;
}
