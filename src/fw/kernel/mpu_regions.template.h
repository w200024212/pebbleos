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

#define MPU_REGION_APP_BASE_ADDRESS         @APP_BASE_ADDRESS@
#define MPU_REGION_APP_SIZE                 @APP_SIZE@
#define MPU_REGION_APP_DISABLED_SUBREGIONS  @APP_DISABLED_SUBREGIONS@

#define MPU_REGION_WORKER_BASE_ADDRESS         @WORKER_BASE_ADDRESS@
#define MPU_REGION_WORKER_SIZE                 @WORKER_SIZE@
#define MPU_REGION_WORKER_DISABLED_SUBREGIONS  @WORKER_DISABLED_SUBREGIONS@
