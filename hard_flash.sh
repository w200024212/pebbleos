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

# Hard Flash
#   Slow down JTAG, bork the watch, speed JTAG back up and then flash normally
echo "Archiving openocd configuration..."
rm -f /tmp/openocd.cfg.bkp
cp openocd.cfg /tmp/openocd.cfg.bkp
echo "Reducing JTAG speed..."
echo "adapter_khz 10" >> openocd.cfg
echo "Resetting and erasing first sector of watch..."
./waf bork
echo "Restoring openocd configuration..."
rm -f openocd.cfg
cp /tmp/openocd.cfg.bkp openocd.cfg
echo "Flashing watch..."
./waf build flash
