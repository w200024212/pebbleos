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


from __future__ import print_function

CRC_POLY = 0x04C11DB7
CRC_WIDTH = 32


def precompute_table(bits):
    lookup_table = []
    for i in xrange(2**bits):
        rr = i << (CRC_WIDTH - bits)
        for x in xrange(bits):
            if rr & 0x80000000:
                rr = (rr << 1) ^ CRC_POLY
            else:
                rr <<= 1
        lookup_table.append(rr & 0xffffffff)
    return lookup_table

print('static const uint32_t s_lookup_table[] = {')
for entry in precompute_table(4):
    print('  0x{:08x},'.format(entry))
print('};')
