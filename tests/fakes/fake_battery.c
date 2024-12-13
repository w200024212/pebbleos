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

#include "fake_battery.h"
#include "kernel/events.h"

static int s_millivolts = 0;
static bool s_usb_connected = false;
static bool s_charging = false;

void fake_battery_init(int millivolts, bool usb_connected, bool charging) {
  s_millivolts = millivolts;
  s_usb_connected = usb_connected;
  s_charging = charging;
}

void fake_battery_set_millivolts(int millivolts) {
  s_millivolts = millivolts;
}

void fake_battery_set_connected(bool usb_connected) {
  s_usb_connected = usb_connected;

  // Trigger a connection event!
  PebbleEvent event = {
    .type = PEBBLE_BATTERY_CONNECTION_EVENT,
    .battery_connection = {
      .is_connected = usb_connected,
    }
  };

  event_put(&event);
}

void fake_battery_set_charging(bool charging) {
  s_charging = charging;
}

int battery_get_millivolts(void) {
  return s_millivolts;
}

bool battery_is_usb_connected(void) {
  return s_usb_connected;
}

bool battery_charge_controller_thinks_we_are_charging(void) {
  return s_charging;
}
