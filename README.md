dwm-mac
=======
This is a port of [KieranQuinn's dwm](https://github.com/KieranQuinn/dwm) to make it accessible being used in **Xquartz**, Apple's version of the X Server.

The following fixes were made to make it more usable on MacBooks, iMacs, etc.:

* Use of `Modkey2` (`Cmd` key) instead of `Alt`/`Option`
    * This means that Apple's `Option` key can still be used to enter special characters such as `@`, `~`, etc.
* A configurable bottom margin if a bottom dock is present (the margin can be defined in `dwm.c` under `BOTTOM_BAR_HEIGHT`).
* A more sensible approach to tagging and switching layouts, with consideration that no system shortcuts are being overwritten.
    * For instance, in vanilla dwm, tag spaces are changed using `Alt+Shift+[Number]). However, if `Alt` is being replaced by `Cmd`, `Cmd+Shift+3` or `Cmd+Shift+4` would take a screenshot instead.

**dwm-mac** uses the following keyboard shortcuts:


The following patches were applied in the original repository:

Patches/Features
----------------
* statuscolors
* statusallmons
* centredfloating
* savefloats
* notitle
* pertag2
* systray
* occupiedcol
* uselessgaps
* keysymfix
* bstack
* runorraise

Screenshot
----------
