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
import bitstring
import json
import collections

parser = argparse.ArgumentParser(description="Pretty print wire-optimized Pebble Bluetooth logs.")
parser.add_argument('filename', help="File containing a series of packed LogBtMessages.")

MESSAGE_SIZE_BYTES = 4 + 4 + 1 + 1 + 2 + 16 + 128

def printBitStream(bit_stream):
    for message in bit_stream.cut(MESSAGE_SIZE_BYTES * 8):
        printMessage(message)
    return

def printMessage(message):
    results = message.unpack('uintbe:16, uintbe:16, uintbe:32, uintbe:8, uintbe:8, uintbe:16, hex:128, hex:1024')
    results = list(results)
    headers = (
        'pebble-message-length',
        'endpoint',
        'timestamp',
        'level',
        'log-message-length',
        'line-number',
        'filename',
        'log-message',
    )
    d = collections.OrderedDict(zip(headers, results))
    d['log-message'] = d['log-message'].decode('hex')[:d['log-message-length']]
    d['filename'] = d['filename'].split('0')[0].decode('hex')
    print(json.dumps(d, indent=4))
    return

def main():
    args = parser.parse_args()
    bit_stream = bitstring.BitStream(filename=args.filename)
    printBitStream(bit_stream)
    return

if __name__ == '__main__':
    main()
