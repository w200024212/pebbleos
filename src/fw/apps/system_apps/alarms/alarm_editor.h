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

#include "services/normal/alarms/alarm.h"
#include "applib/ui/window.h"

typedef enum {
  CREATED,
  DELETED,
  EDITED,
  CANCELLED
} AlarmEditorResult;

typedef void (*AlarmEditorCompleteCallback)(AlarmEditorResult result, AlarmId id,
                                            void *callback_context);

Window* alarm_editor_create_new_alarm(AlarmEditorCompleteCallback editor_complete_callback,
                                      void *callback_context);

void alarm_editor_update_alarm_time(AlarmId alarm_id, AlarmType alarm_type,
                                    AlarmEditorCompleteCallback editor_complete_callback,
                                    void *callback_context);

void alarm_editor_update_alarm_days(AlarmId alarm_id,
                                    AlarmEditorCompleteCallback editor_complete_callback,
                                    void *callback_context);
