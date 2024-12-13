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

import math

# Little tool to generate rounded rect insets, stored as 4 bit uints, packed together into a uint32.

def calc_lookup(radius, is_bottom):
    insets = [0] * (radius + 1)
    
    f = 1 - radius;
    ddF_x = 1;
    ddF_y = -2 * radius;
    x = 0;
    y = radius;
    while(x < y):
        if(f >= 0):
            y -= 1
            ddF_y += 2
            f += ddF_y
        
        x += 1
        ddF_x += 2
        f += ddF_x
        
        insets[radius - y] = radius - x
        insets[radius - x] = radius - y
    
    pack = 0
    rng = xrange(0, radius) if (is_bottom) else xrange(radius - 1, -1, -1)
    for i in rng:
        pack = (pack << 4) | insets[i]
    return pack

def main():
    f = open("roundrect.h", 'wb')
    f.write("static const uint32_t round_top_corner_lookup[] = {\n\t0x0, ")
    for radius in xrange(1, 9):
        f.write("0x%02x, " % calc_lookup(radius, False))
    f.write("\n};\n")
    f.write("static const uint32_t round_bottom_corner_lookup[] = {\n\t0x0, ")
    for radius in xrange(1, 9):
        f.write("0x%02x, " % calc_lookup(radius, True))
    f.write("\n};\n")
    f.close()
    return

if __name__ == "__main__":
    main()
