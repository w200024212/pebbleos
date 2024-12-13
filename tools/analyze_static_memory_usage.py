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

import argparse
from binutils import analyze_elf

if (__name__ == '__main__'):
    parser = argparse.ArgumentParser()
    parser.add_argument('--verbose', action='store_true')
    parser.add_argument('--summary', action='store_true')
    parser.add_argument('--fast', action='store_true')
    parser.add_argument('--sections', default='bdt')
    parser.add_argument('elf_file')
    args = parser.parse_args()

    sections = analyze_elf(args.elf_file, args.sections, args.fast)

    for s in sections.itervalues():
        s.pprint(args.summary, args.verbose)
