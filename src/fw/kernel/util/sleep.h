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

//! @internal
//!
//! Waits for a certain amount of milliseconds by suspending the thread in firmware or by just busy
//! waiting in the bootloader.
//!
//! Note that the thread is slept until the current tick + millis of ticks, so that means that if
//! we're currently part way through a tick, we'll actually wait for a time that's less than
//! expected. For example, if we're at tick n and we want to wait for 1 millisecond, we'll sleep
//! the thread until tick n+1, which will result in a sleep of less than a millisecond, as we're
//! probably halfway through the n-th tick at this time. Also note that your thread isn't
//! guaranteed to be scheduled immediately after you're done sleeping, so you may sleep for longer
//! than you expect.
//!
//! @param millis The number of milliseconds to wait for
void psleep(int millis);

