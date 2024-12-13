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

#include "GATTAPI.h"

#include <stdbool.h>
#include <stdint.h>

bool fake_gatt_is_service_discovery_running(void);

//! @return Number of times GATT_Start_Service_Discovery has been called since fake_gatt_init()
int fake_gatt_is_service_discovery_start_count(void);

//! @return Number of times GATT_Stop_Service_Discovery has been called since fake_gatt_init()
int fake_gatt_is_service_discovery_stop_count(void);

//! Sets the value that the GATT_Start_Service_Discovery fake should return
//! @note fake_gatt_init() will reset this to 0
void fake_gatt_set_start_return_value(int ret_value);

//! Sets the value that the GATT_Stop_Service_Discovery fake should return
//! @note fake_gatt_init() will reset this to 0
void fake_gatt_set_stop_return_value(int ret_value);

int fake_gatt_get_service_changed_indication_count(void);

void fake_gatt_put_service_discovery_event(GATT_Service_Discovery_Event_Data_t *event);

uint16_t fake_gatt_write_last_written_handle(void);

void fake_gatt_put_write_response_for_last_write(void);

void fake_gatt_init(void);
