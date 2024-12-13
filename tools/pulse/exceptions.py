# Copyright 2024 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

class PulseError(Exception):
    pass


class ProtocolAlreadyRegistered(PulseError):
    pass


class FrameDecodeError(PulseError):
    pass


class ReceiveQueueEmpty(PulseError):
    pass


class ResponseParseError(PulseError):
    pass


class CommandTimedOut(PulseError):
    pass


class WriteError(PulseError):
    pass


class EraseError(PulseError):
    pass


class RegionDoesNotExist(PulseError):
    pass


class TTYAutodetectionUnavailable(PulseError):
    pass


class InvalidOperation(PulseError):
    pass
