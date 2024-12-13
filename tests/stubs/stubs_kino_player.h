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

#include "applib/ui/kino/kino_player.h"
#include "util/attributes.h"

void WEAK kino_player_deinit(KinoPlayer *player) {}

void WEAK kino_player_set_callbacks(KinoPlayer *player, KinoPlayerCallbacks callbacks,
                                    void *context) {}

KinoReel * WEAK kino_player_get_reel(KinoPlayer *player) {
  return NULL;
}

void WEAK kino_player_play(KinoPlayer *player) {}

void WEAK kino_player_pause(KinoPlayer *player) {}

void WEAK kino_player_rewind(KinoPlayer *player) {}

void WEAK kino_player_set_reel(KinoPlayer *player, KinoReel *reel, bool take_ownership) {}
