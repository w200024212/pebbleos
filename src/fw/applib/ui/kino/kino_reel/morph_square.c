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

#include "morph_square.h"
#include "transform.h"

#include "applib/applib_malloc.auto.h"
#include "applib/graphics/gdraw_command_transforms.h"
#include "applib/ui/kino/kino_reel.h"
#include "applib/ui/kino/kino_reel_custom.h"
#include "applib/ui/animation_timing.h"

typedef struct {
  KinoReel *reel;
} MorphSquareData;

static void prv_destructor(void *context) {
  MorphSquareData *data = context;
  applib_free(data);
}

static void prv_apply_transform(GDrawCommandList *list, const GSize size, const GRect *from,
                                const GRect *to, AnimationProgress normalized, void *context) {
  MorphSquareData *data = context;

  AnimationProgress curved;
  if (!kino_reel_transform_get_to_reel(data->reel)) {
    curved = animation_timing_curve(normalized, AnimationCurveEaseInOut);
  } else if (normalized < ANIMATION_NORMALIZED_MAX / 2) {
    curved = animation_timing_curve(2 * normalized, AnimationCurveEaseInOut);
  } else {
    curved = animation_timing_curve(2 * (ANIMATION_NORMALIZED_MAX - normalized),
                                    AnimationCurveEaseInOut);
  }

  gdraw_command_list_attract_to_square(list, size, curved);
}

static const TransformImpl MORPH_SQUARE_TRANSFORM_IMPL = {
  .destructor = prv_destructor,
  .apply = prv_apply_transform,
};

KinoReel *kino_reel_morph_square_create(KinoReel *from_reel, bool take_ownership) {
  MorphSquareData *data = applib_malloc(sizeof(MorphSquareData));
  if (!data) {
    return NULL;
  }

  GRect frame = { GPointZero, kino_reel_get_size(from_reel) };

  KinoReel *reel = kino_reel_transform_create(&MORPH_SQUARE_TRANSFORM_IMPL, data);
  if (reel) {
    data->reel = reel;
    kino_reel_transform_set_from_reel(reel, from_reel, take_ownership);
    kino_reel_transform_set_layer_frame(reel, frame);
    kino_reel_transform_set_from_frame(reel, frame);
    kino_reel_transform_set_to_frame(reel, frame);
  } else {
    prv_destructor(data);
  }
  return reel;
}
