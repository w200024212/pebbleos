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

#include "applib/app.h"
#include "applib/tick_timer_service.h"
#include "applib/ui/app_window_stack.h"
#include "applib/ui/text_layer.h"
#include "applib/ui/vibes.h"
#include "applib/ui/window.h"
#include "kernel/pbl_malloc.h"
#include "mfg/mfg_info.h"
#include "mfg/results_ui.h"
#include "process_management/pebble_process_md.h"
#include "process_state/app_state/app_state.h"

typedef struct {
  Window window;

  TextLayer title;

  //! How many times we've vibrated
  int vibe_count;

#if MFG_INFO_RECORDS_TEST_RESULTS
  MfgResultsUI results_ui;
#endif
} AppData;

static void prv_handle_second_tick(struct tm *tick_time, TimeUnits units_changed) {
#if !MFG_INFO_RECORDS_TEST_RESULTS
  AppData *data = app_state_get_user_data();

  const int MAX_VIBE_COUNT = 5;
  if (data->vibe_count >= MAX_VIBE_COUNT) {
    // We've vibed the number of times we wanted to, time to leave!
    app_window_stack_pop(true /* animated */);
    return;
  }

  ++data->vibe_count;
#endif

  vibes_short_pulse();
}

static void prv_handle_init(void) {
  AppData *data = app_malloc_check(sizeof(AppData));
  *data = (AppData) {
    .vibe_count = 0
  };

  app_state_set_user_data(data);

  Window *window = &data->window;
  window_init(window, "");
  window_set_fullscreen(window, true);

  TextLayer *title = &data->title;
  text_layer_init(title, &window->layer.bounds);
  text_layer_set_font(title, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(title, GTextAlignmentCenter);
  text_layer_set_text(title, "VIBE TEST");
  layer_add_child(&window->layer, &title->layer);

#if MFG_INFO_RECORDS_TEST_RESULTS
  mfg_results_ui_init(&data->results_ui, MfgTest_Vibe, window);
#endif

  app_window_stack_push(window, true /* Animated */);

  tick_timer_service_subscribe(SECOND_UNIT, prv_handle_second_tick);
}

static void s_main(void) {
  prv_handle_init();

  app_event_loop();
}

const PebbleProcessMd* mfg_vibe_app_get_info(void) {
  static const PebbleProcessMdSystem s_app_info = {
    .common.main_func = &s_main,
    // UUID: f676085a-b130-4492-b6a1-85492602ba00
    .common.uuid = { 0xf6, 0x76, 0x08, 0x5a, 0xb1, 0x30, 0x44, 0x92,
                     0xb6, 0xa1, 0x85, 0x49, 0x26, 0x02, 0xba, 0x00 },
    .name = "MfgVibe",
  };
  return (const PebbleProcessMd*) &s_app_info;
}

