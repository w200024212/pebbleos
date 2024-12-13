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

# Quick n dirty script to add up hci_active_mode_XXX logs, by debug tag.
# It prints a list of found logs, and a list of the sums per tag.

import re

f = open("log.txt")
r = re.compile('[^\n]+(\+\+|\-\-)no_sniff_count : [0-9]+ \(([A-z]+)\)')
d = {}
for line in f:
    m = r.search(line)
    if m != None:
        is_add = True if m.group(1) == "++" else False
        tag = m.group(2)
        print "tag: {0} {1}".format(tag, "+" if is_add else "-")
        if not tag in d:
            d[tag] = 0
        if is_add:
            d[tag] += 1
        else:
            d[tag] -= 1
print ""
for tag in d:
    print "{0} -> {1}".format(tag, d[tag])
