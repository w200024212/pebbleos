#!/usr/bin/env python
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


from __future__ import with_statement, print_function

import sys
import struct

from fw_binary_info import PebbleFirmwareBinaryInfo


# typedef struct ATTR_PACKED FirmwareDescription {
#   uint32_t description_length;
#   uint32_t firmware_length;
#   uint32_t checksum;
# } FirmwareDescription;
FW_DESCR_FORMAT = '<III'
FW_DESCR_SIZE = struct.calcsize(FW_DESCR_FORMAT)


def _generate_firmware_description_struct(firmware_length, firmware_crc):
    return struct.pack(FW_DESCR_FORMAT, FW_DESCR_SIZE, firmware_length, firmware_crc)


def insert_firmware_description_struct(input_binary, output_binary=None):
    fw_bin_info = PebbleFirmwareBinaryInfo(input_binary)
    with open(input_binary, 'rb') as inf:
        fw_bin = inf.read()
        fw_crc = fw_bin_info.get_crc()

    if output_binary:
        with open(output_binary, 'wb') as outf:
            outf.write(_generate_firmware_description_struct(len(fw_bin), fw_crc))
            outf.write(fw_bin)
    else:
        return _generate_firmware_description_struct(len(fw_bin), fw_crc) + fw_bin


def usage_and_exit():
    print("Usage: %s INPUT_FILE OUTPUT_FILE" % sys.argv[0])
    sys.exit(1)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        usage_and_exit()
    input_binary = sys.argv[1]
    output_binary = sys.argv[2]

    insert_firmware_description_struct(input_binary, output_binary)
