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

#include "touch_event.h"

#include "applib/graphics/gtypes.h"

#include <stdint.h>
#include <stdbool.h>

// TODO: PBL-29944 - move to board configuration
#define MAX_NUM_TOUCHES (2)

typedef enum TouchState {
  TouchState_FingerUp,
  TouchState_FingerDown,
} TouchState;

typedef enum TouchDriverEvent {
  TouchDriverEvent_ControllerError,  // an error occurred in the touch controller
  TouchDriverEvent_PalmDetect,  // a palm detection event occurred

  TouchDriverEventCount
} TouchDriverEvent;

void touch_init(void);

//! Pass a touch update to the service (called by the touch driver)
//! @param touch_idx zero-based index of concurrent touches (1st, 2nd concurrent touch etc.)
//! @param touch_state whether or not the screen is touched
//! @param pos position of touch
//! @param pressure pressure reading from touch
//! @param time_ms time (in milliseconds) that touch occurred. This value should be based on a
//! monotonically increasing clock (should not be affected by setting the system time). This service
//! assumes that touches will be passed in in the order that they occur.
void touch_handle_update(TouchIdx touch_idx, TouchState touch_state, const GPoint *pos,
                         TouchPressure pressure, uint64_t time_ms);

//! Handle driver exceptional events, like palm detection, touch controller errors etc.
//! @param driver_event Driver event
void touch_handle_driver_event(TouchDriverEvent driver_event);

//! Reset the touch service. Called when app context is switched to cancel context about current
//! touches
void touch_reset(void);
