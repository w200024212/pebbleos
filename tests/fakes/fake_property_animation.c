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

#include "applib/ui/property_animation_private.h"
#include "applib/ui/layer.h"

static const PropertyAnimationImplementation s_frame_layer_implementation = {
  .accessors = {
    .setter.grect = (const GRectSetter)layer_set_frame_by_value,
    .getter.grect = (const GRectGetter)layer_get_frame_by_value,
  },
};

PropertyAnimation *WEAK property_animation_create_layer_frame(
    struct Layer *layer, GRect *from_frame, GRect *to_frame) {
  PropertyAnimationPrivate *animation = (PropertyAnimationPrivate *)
      property_animation_create(&s_frame_layer_implementation, layer, from_frame, to_frame);
  if (from_frame) {
    animation->values.from.grect = *from_frame;
    PropertyAnimationImplementation *impl =
        (PropertyAnimationImplementation *)animation->animation.implementation;
    impl->accessors.setter.grect(animation->subject, animation->values.from.grect);
  }
  if (to_frame) {
    animation->values.to.grect = *to_frame;
  }
  return (PropertyAnimation *)animation;
}

