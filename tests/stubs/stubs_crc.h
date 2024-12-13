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

void crc_init(void) {
}

uint32_t crc_calculate_bytes(const void* data, size_t data_length) {
  return 0;
}

uint32_t crc_calculate_flash(uint32_t address, unsigned int num_bytes) {
  return 0;
}

uint8_t crc8_calculate_bytes(const uint8_t *data, unsigned int data_length) {
  return 0;
}

void crc_calculate_incremental_start(void) {
}

void crc_calculate_incremental_stop(void) {
}

uint32_t crc_calculate_file(int fd, uint32_t offset, uint32_t num_bytes) {
  return 0;
}
