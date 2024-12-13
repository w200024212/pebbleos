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

#include "process_management/pebble_process_md.h"

#include "mfg/mfg_mode/mfg_factory_mode.h"
#include "mfg/mfg_apps/mfg_display_burnin.h"
#include "mfg/mfg_apps/mfg_button_app.h"
#include "mfg/mfg_apps/mfg_bt_test_app.h"
#include "mfg/mfg_apps/mfg_display_app.h"
#include "mfg/mfg_apps/mfg_runin_app.h"
#include "mfg/mfg_apps/mfg_func_test.h"

typedef const struct PebbleProcessMd* (*MfgInitFuncType)(void);

static const MfgInitFuncType INIT_MFG_FUNCTIONS[] = {
  &mfg_app_button_test_get_info,
  &mfg_app_runin_get_info,
  &mfg_display_burnin_get_app_info,
  &mfg_app_bt_test_get_info,
  &mfg_app_lcd_test_black_get_info,
  &mfg_app_lcd_test_white_get_info,
  &mfg_app_lcd_test_black_white_border_get_info,
  &mfg_app_lcd_test_cycle_get_info,
  &mfg_func_test_get_app_info,
};
