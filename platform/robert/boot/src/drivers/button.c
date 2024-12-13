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

#include "drivers/button.h"

#include "board/board.h"
#include "drivers/periph_config.h"
#include "drivers/gpio.h"

static void prv_initialize_button(const ButtonConfig* config) {
  // Configure the pin itself
  gpio_input_init_pull_up_down(&config->input, config->pupd);
}

bool button_is_pressed(ButtonId id) {
  const ButtonConfig* button_config = &BOARD_CONFIG_BUTTON.buttons[id];
  return !gpio_input_read(&button_config->input);
}

uint8_t button_get_state_bits(void) {
  uint8_t button_state = 0x00;
  for (int i = 0; i < NUM_BUTTONS; ++i) {
    button_state |= (button_is_pressed(i) ? 0x01 : 0x00) << i;
  }
  return button_state;
}

void button_init(void) {
  periph_config_acquire_lock();

  for (int i = 0; i < NUM_BUTTONS; ++i) {
    prv_initialize_button(&BOARD_CONFIG_BUTTON.buttons[i]);
  }

  periph_config_release_lock();
}
