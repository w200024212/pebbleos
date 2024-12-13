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

#include "util/attributes.h"

#include <stdbool.h>
#include <stdint.h>

//! @internal
//! Structure containing 3-axis magnetometer data
typedef struct PACKED {
 //! magnetic field along the x axis
 int16_t x;
 //! magnetic field along the y axis
 int16_t y;
 //! magnetic field along the z axis
 int16_t z;
} MagData;

typedef enum {
  MagReadSuccess = 0,
  MagReadClobbered = -1,
  MagReadCommunicationFail = -2,
  MagReadMagOff = -3,
  MagReadNoMag = -4,
} MagReadStatus;

typedef enum {
  MagSampleRate20Hz,
  MagSampleRate5Hz
} MagSampleRate;

//! Enable the mag hardware and increment the refcount. Must be matched with a call to
//! mag_release.
void mag_use(void);

//! Enable the mag hardware, configure it in sampling mode and increment the refcount. Must be
//! matched with a call to mag_release.
void mag_start_sampling(void);

//! Release the mag hardware and decrement the refcount. This will turn off the hardware if no one
//! else is still using it (the refcount is still non-zero).
void mag_release(void);

MagReadStatus mag_read_data(MagData *data);

bool mag_change_sample_rate(MagSampleRate rate);

