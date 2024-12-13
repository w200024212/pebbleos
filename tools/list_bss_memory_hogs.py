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

import os
from operator import itemgetter

bash = """arm-none-eabi-objdump -x src/fw/tintin_fw.elf | grep '\.bss' | tail -n+2 | awk '{print $5, $6}' > /tmp/bss_symbols.txt"""
print bash
os.system(bash)

with open('/tmp/bss_symbols.txt', 'r') as f:
    syms = f.readlines()

cleaned = [sym.strip().split() for sym in syms]

parsed = [(int(clean[0], 16), clean[1]) for clean in cleaned if len(clean) > 1]

parsed.sort(key=itemgetter(0))

parsed.reverse()

print 'Top 25 BSS Memory Hogs'
print '~~~~~~~~~~~~~~~~~~~~~~'
for hog in parsed[:25]:
    print '\t',hog[0],'\t',hog[1]
