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

//! Retransmit timer for PULSEv2 Reliable Transport

#pragma once

#include <stdint.h>

//! Start or restart the PULSEv2 reliable transport retransmit timer.
void pulse2_reliable_retransmit_timer_start(
    unsigned int timeout_ms, uint8_t sequence_number);

//! Cancel a running retransmit timer if it has not already expired.
//!
//! It is a no-op to call this function when the timer is already stopped.
void pulse2_reliable_retransmit_timer_cancel(void);

//! The function which is called when the retransmit timer expires.
//!
//! It is executed from the context of the PULSE task.
void pulse2_reliable_retransmit_timer_expired_handler(uint8_t sequence_number);
