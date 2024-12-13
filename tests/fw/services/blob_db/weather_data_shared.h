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

#include "services/normal/blob_db/weather_db.h"

#define WEATHER_DATA_SHARED_WEATHER_DB_NUM_DB_ENTRIES (5)
#define WEATHER_DATA_SHARED_NUM_VALID_TIMESTAMP_ENTRIES \
    (WEATHER_DATA_SHARED_WEATHER_DB_NUM_DB_ENTRIES - 1)

#define TEST_WEATHER_DB_LOCATION_PALO_ALTO "Palo Alto"
#define TEST_WEATHER_DB_LOCATION_KITCHENER "Kitchener"
#define TEST_WEATHER_DB_LOCATION_WATERLOO "Waterloo"
#define TEST_WEATHER_DB_LOCATION_RWC "Redwood City"
#define TEST_WEATHER_DB_LOCATION_SF "San Francisco"

#define TEST_WEATHER_DB_SHORT_PHRASE_SUNNY "Sunny"
#define TEST_WEATHER_DB_SHORT_PHRASE_PARTLY_CLOUDY "Partly Cloudy"
#define TEST_WEATHER_DB_SHORT_PHRASE_HEAVY_SNOW "Heavy Snow"
#define TEST_WEATHER_DB_SHORT_PHRASE_HEAVY_RAIN "Heavy Rain"

void weather_shared_data_initialize_locations_order(void);

void weather_shared_data_init(void);

void weather_shared_data_cleanup(void);

int weather_shared_data_get_index_of_key(const WeatherDBKey *key);

const WeatherDBKey *weather_shared_data_get_key(int index);

WeatherDBEntry *weather_shared_data_get_entry(int index);

size_t weather_shared_data_get_entry_size(int index);

char *weather_shared_data_get_entry_name(int index);

char *weather_shared_data_get_entry_phrase(int index);

void weather_shared_data_assert_entries_equal(const WeatherDBKey *key, WeatherDBEntry *to_check,
                                              WeatherDBEntry *original);

bool weather_shared_data_get_key_exists(WeatherDBKey *key);

size_t weather_shared_data_insert_stale_entry(WeatherDBKey *key);

