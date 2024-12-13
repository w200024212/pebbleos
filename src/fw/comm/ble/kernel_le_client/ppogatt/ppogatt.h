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

#include "applib/bluetooth/ble_client.h"

struct Transport;

typedef enum {
  PPoGATTCharacteristicData,
  PPoGATTCharacteristicMeta,
  PPoGATTCharacteristicNum
} PPoGATTCharacteristic;

void ppogatt_create(void);

void ppogatt_handle_service_discovered(BLECharacteristic *characteristics);

bool ppogatt_can_handle_characteristic(BLECharacteristic characteristic);

void ppogatt_handle_subscribe(BLECharacteristic subscribed_characteristic,
                              BLESubscription subscription_type, BLEGATTError error);

void ppogatt_handle_read_or_notification(BLECharacteristic characteristic, const uint8_t *value,
                                         size_t value_length, BLEGATTError error);

void ppogatt_handle_service_removed(
    BLECharacteristic *characteristics, uint8_t num_characteristics);

void ppogatt_invalidate_all_references(void);

//! Interface for kernel_le_client, to handle the event that the Bluetooth stack has space available
//! again in its outbound queue. It will trigger the PPoGATT module to send out the next packet(s).
void ppogatt_handle_buffer_empty(void);

//! Interface for CommSession, to let it signal the PPoGATT transport that data has been written
//! into the SendBuffer and can be sent out.
void ppogatt_send_next(struct Transport *transport);

void ppogatt_close(struct Transport *transport);

void ppogatt_reset(struct Transport *transport);

void ppogatt_destroy(void);

//! Interface for analytics
void ppogatt_reset_disconnect_counter(void);
