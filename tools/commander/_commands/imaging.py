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

from .. import PebbleCommander, exceptions, parsers


@PebbleCommander.command()
def image_resources(cmdr, pack='build/system_resources.pbpack'):
    """ Image resources.
    """
    import pulse_flash_imaging
    pulse_flash_imaging.load_resources(cmdr.connection, pack,
                                       progress=cmdr.interactive, verbose=cmdr.interactive)


@PebbleCommander.command()
def image_firmware(cmdr, firm='build/prf/src/fw/tintin_fw.bin', address=None):
    """ Image recovery firmware.
    """
    import pulse_flash_imaging
    if address is not None:
        address = int(str(address), 0)
    pulse_flash_imaging.load_firmware(cmdr.connection, firm,
                                      verbose=cmdr.interactive, address=address)
