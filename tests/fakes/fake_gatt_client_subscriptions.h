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

#include "comm/ble/gatt_client_subscriptions.h"

void fake_gatt_client_subscriptions_init(void);

void fake_gatt_client_subscriptions_deinit(void);

void fake_gatt_client_subscriptions_set_subscribe_return_value(BTErrno e);

void fake_gatt_client_subscriptions_assert_subscribe(BLECharacteristic characteristic,
                                                     BLESubscription subscription_type,
                                                     GAPLEClient client);
