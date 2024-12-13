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


from waflib import Logs
from zlib import crc32
from shutil import copyfile
import struct
from elftools.elf.elffile import ELFFile

TEXT_SECTION_NAME = ".text"
TEXT_CRC32_SECTION_NAME = ".text_crc32"

def wafrule(task):
    in_file = task.inputs[0].abspath()
    out_file = task.outputs[0].abspath()

    text_data = get_text_section_data_from_file(in_file)
    if not text_data:
        error = 'Unable to get {} section from {}'.format(TEXT_SECTION_NAME, in_file)
        Logs.pprint('RED', error)
        return error

    crc = crc32(text_data) & 0xFFFFFFFF

    offset = get_text_crc32_section_offset_from_file(in_file)
    if not offset:
        error = 'Unable to get {} section from {}'.format(TEXT_CRC32_SECTION_NAME, in_file)
        Logs.pprint('RED', error)
        return error

    copyfile(in_file, out_file)

    with open(out_file, 'rb+') as file:
        file.seek(offset)
        file.write(struct.pack('<I', crc))


def get_text_section_data_from_file(filename):
    with open(filename, 'rb') as file:
        section = ELFFile(file).get_section_by_name(TEXT_SECTION_NAME)
        return section.data() if section is not None else None

def get_text_crc32_section_offset_from_file(filename):
    with open(filename, 'rb') as file:
        section = ELFFile(file).get_section_by_name(TEXT_CRC32_SECTION_NAME)
        return section['sh_offset'] if section is not None else None

