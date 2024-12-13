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
#include <stdint.h>
#include <time.h>

#include "applib/accel_service.h"
#include "util/shared_circular_buffer.h"

bool accel_start(void);
void accel_stop(void);
bool accel_running(void);

AccelSamplingRate accel_get_sampling_rate(void);
bool accel_set_sampling_rate(AccelSamplingRate);

void accel_reset_pending_accel_event(void);
uint64_t accel_get_latest_timestamp(void);
void accel_get_latest_reading(AccelRawData *data);
void accel_add_consumer(SharedCircularBufferClient *client);
void accel_remove_consumer(SharedCircularBufferClient *client);

uint32_t accel_consume_data(AccelRawData *data, SharedCircularBufferClient *client,
    uint32_t max_samples, uint16_t subsample_num, uint16_t subsample_den);

//! @return result, negative means failure and 0 means pass. See implementation for details
int accel_peek(AccelData *data);

void accel_set_running(bool running);
void accel_set_num_samples(uint8_t num_samples);

// This call is designed to be as lightweight as possible and does not access the hardware.
// Instead, it looks at the last values read from the hardware during normal usage.
bool accel_is_idle(void);

bool accel_update_and_check_is_stationary(void);

extern void accel_manager_dispatch_data(void);

//! The accelerometer supports a changeable sensitivity for shake detection. This call will
//! select whether we want the accelerometer to enter a highly sensitive state with a low
//! threshold, where any minor amount of motion would trigger the system tap event.
//! Note: Setting this value does not ensure that tap detection is enabled.
void accel_set_shake_sensitivity_high(bool sensitivity_high);
