# libOS

libOS is a helper library that makes developing software on top of FreeRTOS on ARM easier.
It is used by and built for the main FW and the Dialog Bluetooth FW.

## Dependencies:

- libc
- libutil
- FreeRTOS
- Availability of an <mcu.h> header file that includes the CMSIS headers (core_cmX.h,
  core_cmFunc.h, etc.)
- A handful of platform specific functions, see platform.c
