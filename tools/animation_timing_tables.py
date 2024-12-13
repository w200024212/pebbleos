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


# These constants are borrowed from animation_timing.h:
ANIMATION_NORMALIZED_MAX = 65535
ANIMATION_NORMALIZED_MIN = 0

# "Standard" animation curves, borrowed from the interwebs:
d = ANIMATION_NORMALIZED_MAX
b = ANIMATION_NORMALIZED_MIN
c = ANIMATION_NORMALIZED_MAX

def easeInOut(t):
    t = t / (d / 2)
    if (t < 1.0):
        return c/2*t*t + b
    t -= 1
    return -c/2 * (t*(t-2) - 1) + b

def easeOut(t):
    t /= d
    return -c * t * (t - 2) + b

def easeIn(t):
    t /= d
    return c*t*t + b

def print_table(name, func):
    nums_per_row = 4
    table = [func(float(t)) for t in xrange(0, 65537, 2048)]
    print "static const uint16_t %s_table[33] = {" % name
    for i in xrange(0, len(table), nums_per_row):
        print '    ' + ', '.join(str(int(n)) for n in table[i:i+nums_per_row]) + ','
    print '};\n'

print_table('ease_in', easeIn)
print_table('ease_out', easeOut)
print_table('ease_in_out', easeInOut)
