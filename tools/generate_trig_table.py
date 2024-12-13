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

def print_sin_table():
    print "{"
    for a in xrange(0, 0xffff + 1, 0xff):
        print str(int(round(math.sin(a*math.pi/0xffff/2.0) * 0xffff))) + ','
    print '}'

def print_atan_table():
    print '{'
    for a in xrange(0, 0xffff + 1, 0xff):
        b = float(a) / float(0xffff)
        print str(int(round(math.atan(b) * 0x8000 / math.pi))*8) + ','
    print '}'

print_sin_table()
print_atan_table()


