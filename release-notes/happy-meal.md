Pebble Firmware v1.8.1 (HM) Release Notes
==================================================
Wed Feb 6 22:00:00 UTC 2013

Pebble Technology is pleased to announce the release of PebbleOS v1.8 for the Pebble SmartWatch. This early release includes...
What's New
----------
* Improved backlight control.
  - Now configurable in the display settings menu.
  - New option "AUTO" which controls the backlight using the ambient light sensor.
* Display settings are now persisted across resets
* Notification popups now time out after 3 minutes
* Persistent debug logs
  - More information is now gathered on the watch to assist with support cases.
  - This data will only be retrieved if the user manually submits a support case.

Bug Fixes
---------
* Fixed an issue with airplane mode causing the watchdog to resetting the watch if toggled too fast.
* Fixed a bug that caused certain MAP/SMS messages to crash the watch.
* Fixed the progress bar resetting between resource and firmware updates.
* Fixed some incorrect battery state transitions and thresholds.
* Fixed infrastructure surrounding updating PRF.


Pebble Firmware v1.8.1 (HM) Release Notes
==================================================
Mon Mar 4 20:30:00 UTC 2013

PebbleOS v1.8.2 is an update that fixes a bug in the PebbleOS v1.8.1 update.
Bug Fixes
---------
* Fixes erratic behavior of automatic backlight setting.
