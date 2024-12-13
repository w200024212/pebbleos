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

#include "sdl_app.h"
#include "sdl_graphics.h"

#include <stdio.h>

extern int app_main(void);

int main(int argc, char **argv) {
  if (!sdl_app_init()) {
    return -1;
  }

  app_main();
  sdl_app_deinit();

  return 0;
}

#include <SDL.h>

bool sdl_app_init(void) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Error: Failed to init SDL\n");
    return false;
  }

  if (!sdl_graphics_init()) {
    printf("Error: Failed to init graphics\n");
    return false;
  }

  return true;
}

void sdl_app_deinit(void) {
  SDL_Quit();
}

void sdl_app_event_loop(void) {
  SDL_Event event;
  int keypress = 0;

  while (!keypress) {
    sdl_graphics_render();
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          keypress = 1;
          break;
        case SDL_KEYDOWN:
          keypress = 1;
          break;
      }
    }
  }
}
