# PebbleOS

This is the latest version of the internal repository from Pebble Technology
providing the software to run on Pebble watches. Proprietary source code has
been removed from this repository and it will not compile as-is. This is for
information only.

This is not an officially supported Google product. This project is not
eligible for the [Google Open Source Software Vulnerability Rewards
Program](https://bughunters.google.com/open-source-security).

## Restoring the Directory Structure

To clarify the licensing of third party code, all non-Pebble code has been
moved into the `third_party/` directory. A python script is provided to
restore the expected structure. It may be helpful to run this script first:

```
./third_party/restore_tree.py
```

## Missing Components

Some parts of the firmware have been removed for licensing reasons,
including:

- All of the system fonts
- The Bluetooth stack, except for a stub that will function in an emulator
- The STM peripheral library
- The voice codec
- ARM CMSIS
- For the Pebble 2 HR, the heart rate monitor driver

Replacements will be needed for these components if you wish to use the
corresponding functionality.
