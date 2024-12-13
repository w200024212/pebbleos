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

#include <inttypes.h>
#include "drivers/rtc.h"

//! Request other modules to update their analytics fields
void analytics_external_update(void);

extern void analytics_external_collect_battery(void);
extern void analytics_external_collect_accel_xyz_delta(void);
extern void analytics_external_collect_app_cpu_stats(void);
extern void analytics_external_collect_app_flash_read_stats(void);
extern void analytics_external_collect_cpu_stats(void);
extern void analytics_external_collect_stop_inhibitor_stats(RtcTicks now_ticks);
extern void analytics_external_collect_bt_parameters(void);
extern void analytics_external_collect_bt_pairing_info(void);
extern void analytics_external_collect_ble_parameters(void);
extern void analytics_external_collect_ble_pairing_info(void);
extern void analytics_external_collect_backlight_settings(void);
extern void analytics_external_collect_notification_settings(void);
extern void analytics_external_collect_system_theme_settings(void);
extern void analytics_external_collect_ancs_info(void);
extern void analytics_external_collect_dls_stats(void);
extern void analytics_external_collect_i2c_stats(void);
extern void analytics_external_collect_system_flash_statistics(void);
extern void analytics_external_collect_stack_free(void);
extern void analytics_external_collect_alerts_preferences(void);
extern void analytics_external_collect_timeline_pin_stats(void);
extern void analytics_external_collect_display_offset(void);
extern void analytics_external_collect_pfs_stats(void);
extern void analytics_external_collect_chip_specific_parameters(void);
extern void analytics_external_collect_bt_chip_heartbeat(void);
extern void analytics_external_collect_kernel_heap_stats(void);
extern void analytics_external_collect_accel_samples_received(void);
