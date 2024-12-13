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

#include "loading_layer.h"

#include "applib/graphics/gtypes.h"
#include "applib/ui/property_animation.h"

#include <string.h>

void loading_layer_init(LoadingLayer *loading_layer, const GRect *frame) {
  *loading_layer = (LoadingLayer) {
    .full_frame = *frame
  };

  ProgressLayer *progress_layer = &loading_layer->progress_layer;
  progress_layer_init(progress_layer, frame);
  progress_layer_set_corner_radius(progress_layer, PROGRESS_SUGGESTED_CORNER_RADIUS);
}

void loading_layer_deinit(LoadingLayer *loading_layer) {
  loading_layer_pause(loading_layer);
  progress_layer_deinit(&loading_layer->progress_layer);
}

void loading_layer_shrink(LoadingLayer *loading_layer, uint32_t delay, uint32_t duration,
                          AnimationStoppedHandler stopped_handler, void *context) {
  loading_layer_pause(loading_layer);

  layer_set_frame((Layer *)loading_layer, &loading_layer->full_frame);
  GRect *start = &loading_layer->full_frame;
  GRect stop = *start;

  stop.origin.x += stop.size.w;
  stop.size.w = 0;

  PropertyAnimation *prop_anim = property_animation_create_layer_frame(
      (Layer *)loading_layer, start, &stop);
  if (!prop_anim) {
    return;
  }

  Animation *animation = property_animation_get_animation(prop_anim);
  // If we failed, pause on the screen for a little.
  animation_set_delay(animation, delay);
  animation_set_duration(animation, duration);
  animation_set_curve(animation, AnimationCurveEaseOut);
  animation_set_handlers(animation, (AnimationHandlers) {
    .stopped = stopped_handler
  }, context);

  loading_layer->animation = animation;
  animation_schedule(animation);
}

void loading_layer_pause(LoadingLayer *loading_layer) {
  if (animation_is_scheduled(loading_layer->animation)) {
    animation_unschedule(loading_layer->animation);
  }
}

void loading_layer_grow(LoadingLayer *loading_layer, uint32_t delay, uint32_t duration) {
  loading_layer_pause(loading_layer);

  if (duration == 0) {
    layer_set_frame((Layer *)loading_layer, &loading_layer->full_frame);
    return;
  }
  GRect start = loading_layer->full_frame;
  start.size.w = 0;
  layer_set_frame((Layer *)loading_layer, &start);

  PropertyAnimation *prop_anim = property_animation_create_layer_frame(
      (Layer *)loading_layer, &start, &loading_layer->full_frame);
  if (!prop_anim) {
    return;
  }

  Animation *animation = property_animation_get_animation(prop_anim);

  animation_set_delay(animation, delay);
  animation_set_duration(animation, duration);
  animation_set_curve(animation, AnimationCurveEaseOut);

  loading_layer->animation = animation;
  animation_schedule(animation);
}
