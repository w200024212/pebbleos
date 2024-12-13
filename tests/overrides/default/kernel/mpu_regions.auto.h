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

#define MPU_REGION_APP_BASE_ADDRESS         0x20000000
#define MPU_REGION_APP_SIZE                 0x40000
#define MPU_REGION_APP_DISABLED_SUBREGIONS  0b11000111

#define MPU_REGION_WORKER_BASE_ADDRESS         0x20014000
#define MPU_REGION_WORKER_SIZE                 0x4000
#define MPU_REGION_WORKER_DISABLED_SUBREGIONS   0b00000011
