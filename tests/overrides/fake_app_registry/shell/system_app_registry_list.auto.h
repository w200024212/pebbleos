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

#include "system_app_ids.auto.h"
#include "resource/resource_ids.auto.h"

extern const PebbleProcessMd *tictoc_get_app_info(void);
extern const PebbleProcessMd *music_app_get_info(void);
extern const PebbleProcessMd *notifications_app_get_info(void);
extern const PebbleProcessMd *alarms_app_get_info(void);
extern const PebbleProcessMd *watchfaces_get_app_info(void);
extern const PebbleProcessMd *settings_get_app_info(void);
extern const PebbleProcessMd *quiet_time_toggle_get_app_info(void);
extern const PebbleProcessMd *workout_app_get_info(void);
extern const PebbleProcessMd *sports_app_get_info(void);

static const AppRegistryEntry APP_RECORDS[] = {

  // System Apps
  {
    .id = APP_ID_TICTOC,
    .type = AppInstallStorageFw,
    .md_fn = &tictoc_get_app_info,
    .color.argb = GColorClearARGB8,
  },
  {
    .id = APP_ID_SETTINGS,
    .type = AppInstallStorageFw,
    .md_fn = &settings_get_app_info
  },
  {
    .id = APP_ID_MUSIC,
    .type = AppInstallStorageFw,
    .md_fn = &music_app_get_info
  },
  {
    .id = APP_ID_NOTIFICATIONS,
    .type = AppInstallStorageFw,
    .md_fn = &notifications_app_get_info
  },
  {
    .id = APP_ID_ALARMS,
    .type = AppInstallStorageFw,
    .md_fn = &alarms_app_get_info
  },
  {
    .id = APP_ID_WATCHFACES,
    .type = AppInstallStorageFw,
    .md_fn = &watchfaces_get_app_info
  },
  {
    .id = APP_ID_QUIET_TIME_TOGGLE,
    .type = AppInstallStorageFw,
    .md_fn = &quiet_time_toggle_get_app_info
  },
  {
    .id = APP_ID_WORKOUT,
    .type = AppInstallStorageFw,
    .md_fn = &workout_app_get_info
  },
  {
    .id = APP_ID_SPORTS,
    .type = AppInstallStorageFw,
    .md_fn = &sports_app_get_info
  },
  // Resource (stored) Apps
  {
    .id = APP_ID_GOLF,
    .type = AppInstallStorageResources,
    .name = "Golf",
    .uuid = { 0xcf, 0x1e, 0x81, 0x6a, 0x9d, 0xb0, 0x45, 0x11, 0xbb, 0xb8, 0xf6, 0x0c, 0x48, 0xca, 0x8f, 0xac },
    .bin_resource_id = RESOURCE_ID_STORED_APP_GOLF,
  }
};
