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

from . import flash_imaging
from . import pulse_logging
from . import pulse_prompt
from .socket import Connection
from .exceptions import PulseError

Connection.register_extension('flash', flash_imaging.FlashImagingProtocol)
Connection.register_extension('logging', pulse_logging.LoggingProtocol)
Connection.register_extension('prompt', pulse_prompt.PromptProtocol)
