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

#include "applib/ui/kino/kino_reel.h"

KinoReel *kino_reel_create_with_resource(uint32_t resource_id) {
  return NULL;
}

KinoReel *kino_reel_create_with_resource_system(ResAppNum app_num, uint32_t resource_id) {
  return NULL;
}

void kino_reel_destroy(KinoReel *reel) {
}

void kino_reel_draw_processed(KinoReel *reel, GContext *ctx, GPoint offset,
                              KinoReelProcessor *processor) {
}

void kino_reel_draw(KinoReel *reel, GContext *ctx, GPoint offset) {
}

bool kino_reel_set_elapsed(KinoReel *reel, uint32_t elapsed_ms) {
  return false;
}

uint32_t kino_reel_get_elapsed(KinoReel *reel) {
  return 0;
}

uint32_t kino_reel_get_duration(KinoReel *reel) {
  return 0;
}

GSize kino_reel_get_size(KinoReel *reel) {
  return (GSize) {};
}

GDrawCommandImage *kino_reel_get_gdraw_command_image(KinoReel *reel) {
  return NULL;
}

GDrawCommandList *kino_reel_get_gdraw_command_list(KinoReel *reel) {
  return NULL;
}

GDrawCommandSequence *kino_reel_get_gdraw_command_sequence(KinoReel *reel) {
  return NULL;
}

GBitmap *kino_reel_get_gbitmap(KinoReel *reel) {
  return NULL;
}

GBitmapSequence *kino_reel_get_gbitmap_sequence(KinoReel *reel) {
  return NULL;
}

KinoReelType kino_reel_get_type(KinoReel *reel) {
  return 0;
}

KinoReel *kino_reel_custom_create(const KinoReelImpl *custom_impl, void *data) {
  return NULL;
}

void *kino_reel_custom_get_data(KinoReel *reel) {
  return NULL;
}

size_t kino_reel_get_data_size(const KinoReel *reel) {
  return 0;
}
