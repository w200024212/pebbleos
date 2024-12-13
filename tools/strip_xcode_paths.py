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

"""
Print out PATH after stripping out the directories inserted by the XCode app.
This is called when we issue a waf build from within XCode because the paths inserted by
XCode interfere with our tintin build. 

When you issue a build from within XCode, it calls into the waf-xcode.sh script. That script
calls this script in order to strip out the XCode directories from PATH before it transfers
control to waf. 
"""

import os

# Strip out the XCode inserted paths in PATH
path = os.getenv('PATH')
elements = path.split(':')
new_elements = []
for x in elements:
    if not 'Xcode.app' in x:
        new_elements.append(x)
        
print ':'.join(new_elements)
