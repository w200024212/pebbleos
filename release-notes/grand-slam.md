Pebble Firmware v1.7.1a (Grand Slam) Release Notes
==================================================
Wed Jan 16 06:00:00 UTC 2013

Pebble Technology is pleased to announce the release of PebbleOS v1.7a for the Pebble smart-watch. This early release includes a number of exciting features including enhancements to Pebble's power-management systems, improved notification support on Android & iOS, and a new, animated user interface.

What's New
----------

Enhanced Power Management: We've completed our first pass at reducing Pebble's power consumption. Users should expect to get approximately 2 days of battery life when paired with an iOS, and 4 days of battery life when paired with an Android device. Please let us know if your battery life doesn't match these estimates. To help track how long your watch has been running we've added an uptime readout to the 'About' screen.

Animated User Interface: v1.7 includes our initial pass at adding animation support to the user interface. This is still very much a work in progress, but we're very excited about what we have so far. If you encounter any poor performance regarding animations on your watch, be sure to let us know on the pebble-hacker mailing list.

Improved User Interface: We've incorporated feedback from our HackerBackers to improve several areas of Pebble's user interface. Please keep the excellent UI/UX feedback coming! Also, check out the new battery gauge in the status bar! (Hint: The battery gauge will not appear until it's time to charge your Pebble).

Android Notification Support: v1.7 now has support for incoming call notifications with call display on Android. Due to telephony limitations imposed by the Android OS, Pebble will only allow you to silence the ringer of an incoming call rather than rejecting it outright.

Android Music Control Support: Pebble now has support for music control on Android. In this release we're only providing support for several stock music players (namely the Samsung, HTC and Google Play apps), however we'll be incrementally adding support for additional players where possible. Did we miss your preferred music player? Be sure to let us know on the pebble-hacker mailing list. Due to limitations in the Spotify, Pandora and Songza apps, it is not possible for the Pebble Android application to control music playback from these services.

Fuzzy Time Watchface: Common Words has been replaced with "Fuzzy Time", a watchface that displays the time accurate to the nearest 5 minutes. This is the first of many watchfaces that will be available at launch.
Bug Fixes

Bug Fixes
---------
* The Pebble's Bluetooth address is now shown when in airplane mode.
* Lines in the notification app no longer end in an unprintable character (i.e. a box).
* Fixed issues affecting the accuracy of Pebble's internal clock.
* Fixed several UI glitches present in the 'Bluetooth' settings screen while in Airplane mode.
* Fixed a bug causing some notifications not to be displayed without content.

---

PebbleOS v1.7.0b (Grand Slam) Release Notes
===========================================
Thu Jan 17 04:00:00 UTC 2013

PebbleOS v1.7.0b is an update that fixes several critical bugs in PebbleOS v1.7.0a update.

Bug Fixes
---------
* Fixed a system stability problem causing sporadic reboots.
* Fixed an issue causing alarms to go off at the wrong time.
* Time is now correctly saved across device reboots.
* Fixed a bug that was causing stale data to be displayed in MAP notifications sent from iOS.
* Fixed a text-rendering bug that caused the Sliding Text watchface to occasionally freeze.

---

PebbleOS v1.7.1 (Grand Slam) Release Notes
==========================================
Tue Jan 22 23:00:00 UTC 2013

PebbleOS v1.7.1 is an update that fixes several critical bugs in the PebbleOS v1.7.1 update.

Bug Fixes
---------
* Fixed issues in Getting Started/Firmware Update processes.
* Fixed an issue with the notification UI showing the wrong icon.
* Fixed a few animation issues where the status bar behaved incorrectly.
* Fixed a few bugs in the HFP (iOS only) call notification UI.
* Changed the tap-to-backlight from the "up the screen" axis to the "into the screen" axis.

---

PebbleOS v1.7.2 (Grand Slam) Release Notes
==========================================
Thu Jan 24 03:00:00 UTC 2013

PebbleOS v1.7.2 is an update that fixes a bug in the PebbleOS v1.7.1 update.

Bug Fixes
---------
* Fixed an issue related to manufacturing line testability
