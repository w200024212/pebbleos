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

#include "drivers/stm32f2/rtc_calibration.h"

#include "clar.h"

// Stubs and stuff
#include "stubs_logging.h"
#include "mcu.h"

#define TARGET_FREQUENCY_mHZ (32768 * 1000)
#define ALTERNATE_FREQUENCY_mHZ (1000000 * 1000)

// Tests

void test_rtc_calibration__no_calibration_required(void) {
  RTCCalibConfig config = rtc_calibration_get_config(32768000, TARGET_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 0);
}

void test_rtc_calibration__slightly_slow_but_not_enough_to_calibrate(void) {
  // Approximately -2.01ppm
  RTCCalibConfig config = rtc_calibration_get_config(32767934, TARGET_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 0);
}

void test_rtc_calibration__just_slow_enough_to_calibrate(void) {
  // Approximately -2.04ppm
  RTCCalibConfig config = rtc_calibration_get_config(32767933, TARGET_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 1);
  cl_assert_equal_i(config.sign, RTC_CalibSign_Positive);
}

void test_rtc_calibration__slightly_fast_but_not_enough_to_calibrate(void) {
  // Approximately +1.01ppm
  RTCCalibConfig config = rtc_calibration_get_config(32768033, TARGET_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 0);
}

void test_rtc_calibration__just_fast_enough_to_calibrate(void) {
  // Approximately +1.04ppm
  RTCCalibConfig config = rtc_calibration_get_config(32768034, TARGET_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 1);
  cl_assert_equal_i(config.sign, RTC_CalibSign_Negative);
}

void test_rtc_calibration__out_of_bounds_slow(void) {
  // Approximately -130ppm
  RTCCalibConfig config = rtc_calibration_get_config(32763740, TARGET_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 31);
  cl_assert_equal_i(config.sign, RTC_CalibSign_Positive);
}

void test_rtc_calibration__out_of_bounds_fast(void) {
  // Approximately +70ppm
  RTCCalibConfig config = rtc_calibration_get_config(32770294, TARGET_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 31);
  cl_assert_equal_i(config.sign, RTC_CalibSign_Negative);
}

void test_rtc_calibration__different_target_frequency_not_fast_enough(void) {
  // Approximately +1.017ppm
  RTCCalibConfig config = rtc_calibration_get_config(1000001017, ALTERNATE_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 0);
}

void test_rtc_calibration__different_target_frequency_just_fast_enough(void) {
  // Approximately +1.018ppm
  RTCCalibConfig config = rtc_calibration_get_config(1000001018, ALTERNATE_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 1);
  cl_assert_equal_i(config.sign, RTC_CalibSign_Negative);
}

void test_rtc_calibration__invalid_frequency(void) {
  // Bigboards don't have a frequency stored in their mfg info registry.
  RTCCalibConfig config = rtc_calibration_get_config(0, TARGET_FREQUENCY_mHZ);
  cl_assert_equal_i(config.units, 0);
}
