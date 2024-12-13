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

import tempfile

import png
from bitarray import bitarray

from .. import PebbleCommander, exceptions, parsers


def chunks(l, n):
    for i in xrange(0, len(l), n):
        yield l[i:i+n]


def convert_8bpp(data):
    ret = []
    for pixel in data:
        pixel = ord(pixel)
        red, green, blue = (((pixel >> n) & 0b11) * 255 / 3 for n in (4, 2, 0))
        ret.extend((red, green, blue))
    return ret


def convert_1bpp(data, width):
    # Chop off the unused bytes at the end of each row
    bytes_per_row = (width / 32 + 1) * 4
    data = ''.join(c[:width/8] for c in chunks(data, bytes_per_row))
    ba = bitarray(endian='little')
    ba.frombytes(data)
    return ba.tolist()


def framebuffer_to_png(data, png_path, width, bpp):
    if bpp == 1:
        data = convert_1bpp(data, width)
        channels = 'L'
    elif bpp == 8:
        data = convert_8bpp(data)
        channels = 'RGB'

    data = list(chunks(data, width*len(channels)))

    png.from_array(data, mode='%s;%d' % (channels, bpp)).save(png_path)


@PebbleCommander.command()
def window_stack(cmdr):
    """ Dump the window stack.
    """
    return cmdr.send_prompt_command("window stack")


@PebbleCommander.command()
def modal_stack(cmdr):
    """ Dump the modal stack.
    """
    return cmdr.send_prompt_command("modal stack")


@PebbleCommander.command()
def screenshot(cmdr, filename=None):
    """ Take a screenshot.
    """

    if filename is None:
        filename = tempfile.mktemp(suffix='.png')

    with cmdr.connection.bulkio.open('framebuffer') as handle:
        attrs = handle.stat()
        data = str(handle.read(attrs.length))

    framebuffer_to_png(data, filename, attrs.width, attrs.bpp)
    return filename
