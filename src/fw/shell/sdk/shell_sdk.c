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

#include "shell_sdk.h"

#include "process_management/app_install_manager.h"

AppInstallId s_last_installed_app = INSTALL_ID_INVALID;

AppInstallId shell_sdk_get_last_installed_app(void) {
  return s_last_installed_app;
}

void shell_sdk_set_last_installed_app(AppInstallId app_id) {
  s_last_installed_app = app_id;
}

bool shell_sdk_last_installed_app_is_watchface() {
  return app_install_is_watchface(shell_sdk_get_last_installed_app());
}
