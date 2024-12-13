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

#include "util/uuid.h"
#include "applib/voice/dictation_session.h"
#include "services/normal/voice_endpoint.h"

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct VoiceUiData VoiceWindow;

VoiceWindow *voice_window_create(char *buffer, size_t buffer_size,
                                 VoiceEndpointSessionType session_type);

void voice_window_destroy(VoiceWindow *voice_window);

// Push the voice window from App task or Main task
DictationSessionStatus voice_window_push(VoiceWindow *voice_window);

void voice_window_pop(VoiceWindow *voice_window);

void voice_window_set_confirmation_enabled(VoiceWindow *voice_window, bool enabled);

void voice_window_set_error_enabled(VoiceWindow *voice_window, bool enabled);

void voice_window_reset(VoiceWindow *voice_window);
