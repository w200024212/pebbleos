/**
 * Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

var fs = require('fs');

module.exports = function(source) {
    // Set this loader to cacheable
    this.cacheable();

    // Whitelist files in the current project
    var whitelisted_folders = [this.options.context];

    // Whitelist files from the SDK-appended search paths
    whitelisted_folders = whitelisted_folders.concat(this.options.resolve.root);

    // Iterate over whitelisted file paths
    for (var i=0; i<whitelisted_folders.length; i++) {
        // If resource file is from a whitelisted path, return source
        if (~this.resourcePath.indexOf(fs.realpathSync(whitelisted_folders[i]))) {
            return source;
        }
    }

    // If the resource file is not from a whitelisted path, emit an error and fail the build
    this.emitError("Requiring a file outside of the current project folder is not permitted.");
    return "";
};
