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

#include "drivers/accel.h"
#include "drivers/imu.h"
#include "drivers/imu/bma255/bma255.h"

void imu_init(void) {
  bma255_init();
}

void imu_power_up(void) {
  // NYI
}

void imu_power_down(void) {
  // NYI
}

#if !TARGET_QEMU

////////////////////////////////////
// Accel
//
////////////////////////////////////

void accel_enable_double_tap_detection(bool on) {
}

bool accel_get_double_tap_detection_enabled(void) {
    return false;
}

#endif /* !TARGET_QEMU */
