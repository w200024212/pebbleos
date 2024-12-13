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

#include "vibe_intensity.h"

#include "services/common/i18n/i18n.h"
#include "services/common/vibe_pattern.h"
#include "services/normal/notifications/alerts_preferences_private.h"

uint8_t get_strength_for_intensity(VibeIntensity intensity) {
  switch (intensity) {
    case VibeIntensityLow:
      return 40;
    case VibeIntensityMedium:
      return 60;
    case VibeIntensityHigh:
      return 100;
    default:
      return 100;
  }
}

void vibe_intensity_init(void) {
  vibe_intensity_set(vibe_intensity_get());
}

void vibe_intensity_set(VibeIntensity intensity) {
  vibes_set_default_vibe_strength(get_strength_for_intensity(intensity));
}

VibeIntensity vibe_intensity_get(void) {
  return alerts_preferences_get_vibe_intensity();
}

const char *vibe_intensity_get_string_for_intensity(VibeIntensity intensity) {
  switch (intensity) {
    case VibeIntensityLow: {
      /// Standard vibration pattern option that has a low intensity
      return i18n_noop("Standard - Low");
    }
    case VibeIntensityMedium: {
      /// Standard vibration pattern option that has a medium intensity
      return i18n_noop("Standard - Medium");
    }
    case VibeIntensityHigh: {
      /// Standard vibration pattern option that has a high intensity
      return i18n_noop("Standard - High");
    }
    default: {
      return NULL;
    }
  }
}

VibeIntensity vibe_intensity_cycle_next(VibeIntensity intensity) {
  return (intensity + 1) % VibeIntensityNum;
}
