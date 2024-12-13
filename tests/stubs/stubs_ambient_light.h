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

void ambient_light_init(void) {
}
uint32_t ambient_light_get_light_level(void) {
	return 0;
}
void command_als_read(void) {
}
uint32_t ambient_light_get_dark_threshold(void) {
	return 0;
}
void ambient_light_set_dark_threshold(uint32_t new_threshold) {
}
bool ambient_light_is_light(void) {
	return false;
}
