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
import boto
import boto.s3
import boto.s3.key
import hashlib
import json
import os.path
from sh import git, head
import sys
import zipfile

class PebbleBundle(object):
    MANIFEST_FILENAME = 'manifest.json'

    def __init__(self, bundle_path):
        bundle_abs_path = os.path.abspath(bundle_path)
        if not os.path.exists(bundle_abs_path):
            raise "Bundle does not exist: " + bundle_path

        self.zip = zipfile.ZipFile(bundle_abs_path)
        self.path = bundle_abs_path
        self.manifest = None

    def get_manifest(self):
        if (self.manifest):
            return self.manifest

        if self.MANIFEST_FILENAME not in self.zip.namelist():
            raise "Could not find {}; are you sure this is a PebbleBundle?".format(self.MANIFEST_FILENAME)

        self.manifest = json.loads(self.zip.read(self.MANIFEST_FILENAME))
        return self.manifest

    def is_firmware_bundle(self):
        return 'firmware' in self.get_manifest()

    def get_firmware_info(self):
        if not self.is_firmware_bundle():
            return None

        return self.get_manifest()['firmware']


S3_PUBLIC_URL = 'https://pebblefw.s3.amazonaws.com/'
S3_BUCKET = 'pebblefw'
LATEST_MANIFEST = 'latest.json'
BUNDLE_DIRECTORY = 'pbz'
LAYOUTS_DIRECTORY = 'layouts'

RECOVERY_MANIFESTS = {
        "bigboard" : {
            "friendlyVersion" : "v1.4",
            "timestamp" : 1354827516,
            "sha-256" : "61f59c29b7e1c72c2e4de6848affb56ddd1f4c79512bfb9325aa99a650105d19",
            "url" : "https://pebblefw.s3.amazonaws.com/pebble/bigboard/release/pbz/recovery_bigboard_v1.4.pbz",
            "notes" : "Bigboard Recovery Firmware"
            },
        "ev2_4" : {
            "friendlyVersion" : "v1.5.2",
            "timestamp" : 1356919500,
            "sha-256" : "1ca285d65d80b48b90bab85c5f9e54c907414adffa6f1168beec8aac5d6f32a2",
            "url" : "https://pebblefw.s3.amazonaws.com/pebble/ev2_4/release/pbz/recovery_ev2_4_v1.5.2.pbz",
            "notes" : "Official Recovery Firmware"
            },
        "bb2" : {
            "friendlyVersion" : "v1.5.5",
            "timestamp" : 1377981535,
            "sha-256" : "620cfcadc8d28240048ffa01eb6984b06774a584349f178564e1548ecc813903",
            "url" : "https://pebblefw.s3.amazonaws.com/pebble/bb2/release/pbz/recovery_bb2_v1.5.5.pbz",
            "notes" : "Official Recovery Firmware"
            },
        "v1_5" : {
            "friendlyVersion" : "v1.5.5",
            "timestamp" : 1377981535,
            "sha-256" : "d952ffc4b46d1db965ac8ff0cffca645c1f9c9a8f296cf5da452f698b5bc15ce",
            "url" : "https://pebblefw.s3.amazonaws.com/pebble/v1_5/release/pbz/recovery_v1_5_v1.5.5.pbz",
            "notes" : "Official Recovery Firmware"
            },
        "v2_0" : {
            "friendlyVersion" : "v1.5.5",
            "timestamp" : 1377981535,
            "sha-256" : "07fd7c6ef5a1fbf51b8122bca3e72772015b5f210e905f30e853c65ae02ee09b",
            "url" : "https://pebblefw.s3.amazonaws.com/pebble/v2_0/release/pbz/recovery_v2_0_v1.5.5.pbz",
            "notes" : "Official Recovery Firmware"
            },
        "snowy_evt2" : {
            "friendlyVersion" : "v3.0.2-prf",
            "timestamp" : 1430231686,
            "sha-256" : "5579978e73db5d57831d4e1b8e3416b66fe94f5f19d3eb3ac49fcd54270935f3",
            "url" : "http://pebblefw.s3.amazonaws.com/pebble/snowy_evt2/release-v3/pbz/recovery_snowy_evt2_v3.0.2-prf.pbz",
            "notes" : "Official Recovery Firmware"
            },
        "snowy_dvt" : {
            "friendlyVersion" : "v3.0.2-prf",
            "timestamp" : 1430231686,
            "sha-256" : "3338d94af5b97e94fe0e0dee5eddae7ea9c8f299b64070d1d1a692948c651a02",
            "url" : "http://pebblefw.s3.amazonaws.com/pebble/snowy_dvt/release-v3/pbz/recovery_snowy_dvt_v3.0.2-prf.pbz",
            "notes" : "Official Recovery Firmware"
            },
        "snowy_s3" : {
            "friendlyVersion" : "v3.0.3-prf",
            "timestamp" : 1435167301,
            "sha-256" : "0e5bd3d327c5180506b20ef33aed1601037df0030683b27d68c16e4836c4def0",
            "url" : "http://pebblefw.s3.amazonaws.com/pebble/snowy_s3/release-v3/pbz/recovery_snowy_s3_v3.0.3-prf.pbz",
            "notes" : "Official Recovery Firmware"
            },
        "spalding" : {
            "friendlyVersion" : "v3.2-prf5",
            "timestamp" : 1440968436,
            "sha-256" : "f6d3616b423d32618a1a3615ae8f8d5526941c7b6311be45e4387045c7eb7602",
            "url" : "https://pebblefw.s3.amazonaws.com/pebble/spalding/release-v3/pbz/recovery_s4_pvt_prf5.pbz",
            "notes" : "Official Recovery Firmware"
            },
        "spalding_evt" : {
            "friendlyVersion" : "v3.2-prf5",
            "sha-256": "f9c2bb857952c034c7122b67f5178a25fcdf9ef8cce3d3bd8c2c8671676958c2",
            "url" : "https://pebblefw.s3.amazonaws.com/pebble/spalding/release-v3/pbz/recovery_s4_evt_prf5.pbz",
            "timestamp": 1440968436,
            "notes" : "Official Recovery Firmware"
            }
        }

def build_s3_path(*args):
    return 'pebble/' + '/'.join(args)

def __git_tag():
    return str(git.describe()).strip()

def generate_update_manifest(bundle, bundle_s3_key, layouts_s3_key, notes):
    bundle_path = os.path.abspath(bundle.path)
    board = bundle.get_firmware_info()['hwrev']

    timestamp = bundle.get_firmware_info()['timestamp']

    with open(bundle_path, 'rb') as normal_bundle:
        bundle_data = normal_bundle.read()
        sha256 = hashlib.sha256(bundle_data).hexdigest()

    bundle_url = S3_PUBLIC_URL + bundle_s3_key
    layouts_url = S3_PUBLIC_URL + layouts_s3_key

    manifest = {
        'normal' : {
            'friendlyVersion' : __git_tag(),
            'timestamp' : timestamp,
            'sha-256' : sha256,
            'url' : bundle_url,
            'layouts' : layouts_url,
            'notes' : notes
            },
        'recovery' : RECOVERY_MANIFESTS[board]
        }

    return json.dumps(manifest)

def push_to_s3(bundle_path, layouts_path, stage, notes, update_latest=False, dry_run=False):
    conn = boto.connect_s3()

    bundle = PebbleBundle(bundle_path)
    bundle_path = bundle.path
    bundle_filename = os.path.basename(bundle_path)

    git_tag = str(git.describe()).strip()
    board = bundle.get_firmware_info()['hwrev']
    bundle_key = build_s3_path(board, stage, BUNDLE_DIRECTORY, bundle_filename)
    layouts_key = build_s3_path(board, stage, LAYOUTS_DIRECTORY, __git_tag() + '_layouts.json')
    manifest_key = build_s3_path(board, stage, __git_tag() + '.json')
    with open(notes, 'r') as f:
        notes_txt = f.read().strip()

    manifest_contents = generate_update_manifest(bundle, bundle_key, layouts_key, notes_txt)

    if dry_run:
        print manifest_contents
        return

    fw_bucket = boto.s3.bucket.Bucket(conn, S3_BUCKET)

    # Upload the bundle to S3
    bundle_obj = boto.s3.key.Key(fw_bucket, bundle_key)
    bundle_obj.set_contents_from_filename(bundle_path)
    bundle_obj.set_acl('public-read')
    print 'PUT ' + bundle_key

    bundle_obj = boto.s3.key.Key(fw_bucket, layouts_key)
    bundle_obj.set_contents_from_filename(layouts_path)
    bundle_obj.set_acl('public-read')
    print 'PUT ' + layouts_key

    manifest_obj = boto.s3.key.Key(fw_bucket, manifest_key)
    manifest_obj.set_contents_from_string(manifest_contents)
    manifest_obj.set_acl('public-read')
    print 'PUT ' + manifest_key

    if update_latest:
        latest_key = build_s3_path(board, stage, LATEST_MANIFEST)
        latest_obj = boto.s3.key.Key(fw_bucket, latest_key)
        # prevent caching of the latest file
        headers = {'Cache-Control': 'max-age=0'}
        latest_obj.set_contents_from_string(manifest_contents, headers=headers)
        latest_obj.set_acl('public-read')
        print 'PUT ' + latest_key

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--notes', metavar='NOTES', required=True,
                        help='path to very brief release notes')
    parser.add_argument('--bundle', metavar='BUNDLE_PATH', required=True,
                        help='path to the bundle')
    parser.add_argument('--layouts', metavar='LAYOUTS_PATH', required=True,
                        help='path to the layouts json')
    stage_choices = [
        'release', 'test', 'release-v2',
        'release-v3', 'beta', 'nightly',
        'porksmoothie', 'garlicsoda', 'anchovietea'
        ]
    parser.add_argument('--stage', metavar='STAGE', choices=stage_choices,
                        required=True, help='the target release stage')
    parser.add_argument("--latest", action="store_true",
                        help="update the release stage's 'latest.json' manifest")
    parser.add_argument("-d", "--dry_run", action="store_true", help="don't modify s3")

    args = parser.parse_args()

    print args

    print 'HI'
    push_to_s3(bundle_path=args.bundle,
               layouts_path=args.layouts,
               stage=args.stage,
               notes=args.notes,
               update_latest=args.latest,
               dry_run=args.dry_run)
    print 'BYE'

if (__name__ == '__main__'):
    main()
