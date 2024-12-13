
This is the source directory for the SDK. As part of a normal waf build, this directory is mostly copied into the tintin/build/sdk directory. Scripts from tintin/tools/generate_native_sdk are also used to place other files into that directory based on auto-generated export tables pulled from the source.

To export a symbol to be usable from the SDK, add it to tintin/tools/generate_native_sdk/exported_symbols.json

The wscript in this directory is used to build files into the tintin/build/sdk directory. src_wscript is the build script that becomes tintin/build/sdk/wscript, which is to be used by app developers to build their apps.

For info on actually building apps, see src_readme.txt (the readme for the output redistributable SDK).

