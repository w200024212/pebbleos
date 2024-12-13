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

#include "launcher_app_glance.h"

#include "launcher_menu_layer.h"

#include "applib/app_glance.h"
#include "applib/ui/kino/kino_reel_custom.h"
#include "kernel/pbl_malloc.h"
#include "resource/resource_ids.auto.h"
#include "system/passert.h"
#include "util/string.h"

void launcher_app_glance_init(LauncherAppGlance *glance, const Uuid *uuid, KinoReel *impl,
                              bool should_consider_slices,
                              const LauncherAppGlanceHandlers *handlers) {
  if (!glance || !uuid) {
    return;
  }

  *glance = (LauncherAppGlance) {
    .uuid = *uuid,
    .reel = impl,
    .should_consider_slices = should_consider_slices,
  };

  if (handlers) {
    glance->handlers = *handlers;
  }

  launcher_app_glance_update_current_slice(glance);
}

void launcher_app_glance_update_current_slice(LauncherAppGlance *glance) {
  if (!glance || !glance->should_consider_slices) {
    return;
  }

  const Uuid *uuid = &glance->uuid;

  AppGlanceSliceInternal current_slice = {};
  // If there's no current slice, this function won't modify the zeroed-out current_slice, so we
  // can safely set the glance's current slice to current_slice either way
  app_glance_service_get_current_slice(uuid, &current_slice);
  glance->current_slice = current_slice;

  if (glance->handlers.current_slice_updated) {
    glance->handlers.current_slice_updated(glance);
  }

  launcher_app_glance_service_notify_glance_changed(glance->service);
}

void launcher_app_glance_draw(GContext *ctx, const GRect *frame, LauncherAppGlance *glance,
                              bool is_highlighted) {
  if (!glance || !frame || !ctx) {
    return;
  }

  glance->size = frame->size;
  glance->is_highlighted = is_highlighted;
  kino_reel_draw(glance->reel, ctx, frame->origin);
}

void launcher_app_glance_notify_service_glance_changed(LauncherAppGlance *glance) {
  if (!glance) {
    return;
  }
  launcher_app_glance_service_notify_glance_changed(glance->service);
}

void launcher_app_glance_destroy(LauncherAppGlance *glance) {
  if (!glance) {
    return;
  }

  kino_reel_destroy(glance->reel);
  app_free(glance);
}
