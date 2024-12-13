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

#include "services/normal/app_glances/app_glance_service.h"
#include "system/status_codes.h"
#include "util/attributes.h"
#include "util/time/time.h"
#include "util/uuid.h"

#include <stdint.h>

// -------------------------------------------------------------------------------------------------
// AppGlanceDB Implementation

status_t app_glance_db_insert_glance(const Uuid *uuid, const AppGlance *glance);

status_t app_glance_db_read_glance(const Uuid *uuid, AppGlance *glance_out);

status_t app_glance_db_read_creation_time(const Uuid *uuid, time_t *time_out);

status_t app_glance_db_delete_glance(const Uuid *uuid);

// -------------------------------------------------------------------------------------------------
// BlobDB API Implementation

void app_glance_db_init(void);

status_t app_glance_db_flush(void);

status_t app_glance_db_insert(const uint8_t *key, int key_len, const uint8_t *val, int val_len);

int app_glance_db_get_len(const uint8_t *key, int key_len);

status_t app_glance_db_read(const uint8_t *key, int key_len, uint8_t *val_out, int val_out_len);

status_t app_glance_db_delete(const uint8_t *key, int key_len);
