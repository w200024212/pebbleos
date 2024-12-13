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

#include "quiet_time.h"

#include "applib/app.h"
#include "applib/ui/action_toggle.h"
#include "process_management/app_manager.h"
#include "services/common/i18n/i18n.h"
#include "services/normal/notifications/do_not_disturb_toggle.h"

static void prv_main(void) {
  do_not_disturb_toggle_push(ActionTogglePrompt_Auto, true /* set_exit_reason */);
  app_event_loop();
}

const PebbleProcessMd *quiet_time_toggle_get_app_info(void) {
  static const PebbleProcessMdSystem s_app_info = {
    .common = {
      .main_func = &prv_main,
      .uuid = QUIET_TIME_TOGGLE_UUID,
      .visibility = ProcessVisibilityQuickLaunch,
    },
    .name = i18n_noop("Quiet Time"),
  };
  return &s_app_info.common;
}
