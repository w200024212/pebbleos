# PBL STD Overrides
The files in this directory are used to override the `app_state` header included
by `pbl_std.c`, as this header makes use of the reentry structure (`_reent`), which
is not defined when compiling non-ARM code, we override it with our own which makes
use of our faked headers.
