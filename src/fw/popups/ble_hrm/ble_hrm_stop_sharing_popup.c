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

#include "ble_hrm_stop_sharing_popup.h"

#include "applib/ui/dialogs/simple_dialog.h"
#include "resource/resource_ids.auto.h"
#include "services/common/i18n/i18n.h"
#include "util/time/time.h"

#define BLE_HRM_CONFIRMATION_TIMEOUT_MS (2 * MS_PER_SECOND)

SimpleDialog *ble_hrm_stop_sharing_popup_create(void) {
  SimpleDialog *simple_dialog = simple_dialog_create("Stopped Sharing");
  Dialog *dialog = simple_dialog_get_dialog(simple_dialog);

  const char *msg = i18n_get("Heart Rate Not Shared", dialog);
  dialog_set_text(dialog, msg);
  dialog_set_icon(dialog, RESOURCE_ID_BLE_HRM_NOT_SHARED);
  dialog_set_timeout(dialog, BLE_HRM_CONFIRMATION_TIMEOUT_MS);
  simple_dialog_set_icon_animated(simple_dialog, false);
  i18n_free(msg, dialog);
  return simple_dialog;
}
