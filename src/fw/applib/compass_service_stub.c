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

#if CAPABILITY_HAS_MAGNETOMETER
#error "Use fw/applib/compass_service.c instead if we don't have a magnetometer"
#endif

//! @file compass_service_stub.c
//!
//! Implements the compass_service for devices that don't actually have a compass. See
//! fw/applib/compass_service.c for the real implementation for boards that do have a compass.

#include "compass_service.h"

#include "process_management/process_manager.h"

//! @return which status value we should use to indicate we have no compass
static CompassStatus prv_get_status(void) {
  if (process_manager_compiled_with_legacy2_sdk() ||
      process_manager_compiled_with_legacy3_sdk()) {
    // This value is new in 4.x. Use the old CompassStatusDataInvalid value instead for old apps
    // that may not know how to handle the previously undefined status.
    return CompassStatusDataInvalid;
  }

  return CompassStatusUnavailable;
}

int compass_service_peek(CompassHeadingData *data) {
  *data = (CompassHeadingData) {
    .compass_status = prv_get_status()
  };

  return 0;
}

int compass_service_set_heading_filter(CompassHeading filter) {
  // Just ignore the filter, we're not going to call the handler regularly anyway.
  return 0;
}

void compass_service_subscribe(CompassHeadingHandler handler) {
  CompassHeadingData data = {
    .compass_status = prv_get_status()
  };

  // Call the handler once to indicate status
  handler(data);
}

void compass_service_unsubscribe(void) {
  // Nothing to do because we never handle the subscribe in the first place
}
