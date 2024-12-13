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

#include <stdbool.h>

typedef struct SMPairingInfo SMPairingInfo;
typedef struct SM128BitKey SM128BitKey;

bool sm_is_pairing_info_equal_identity(const SMPairingInfo *a, const SMPairingInfo *b);

bool sm_is_pairing_info_empty(const SMPairingInfo *p);

bool sm_is_pairing_info_irk_not_used(const SM128BitKey *irk_key);
