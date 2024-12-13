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

#include "process_management/app_install_types.h"

typedef struct CompositorTransition CompositorTransition;

const CompositorTransition *shell_get_watchface_compositor_animation(bool watchface_is_destination);

const CompositorTransition *shell_get_close_compositor_animation(AppInstallId current_app_id,
                                                                 AppInstallId next_app_id);

const CompositorTransition *shell_get_open_compositor_animation(AppInstallId current_app_id,
                                                                AppInstallId next_app_id);
