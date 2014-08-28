dwm-mac
=======
This is a port of `dwm` to make it more accessible being used in **Xquartz**, Apple's version of the X Server.

The following fixes were made to make it more usable on MacBooks, iMacs, etc.:

* Use of `Modkey2` (`Cmd` key) instead of `Alt`/`Option`
    * This means that Apple's `Option` key can still be used to enter special characters such as `@`, `~`, etc.
* A configurable bottom margin if a bottom dock is present (the margin can be defined in `dwm.c` under `BOTTOM_BAR_HEIGHT`).
* A more sensible approach to tagging and switching layouts, with consideration that no system shortcuts are being overwritten.
    * For instance, in vanilla dwm, tag spaces are changed using `Alt+Shift+[Number]`). However, if `Alt` is being replaced by `Cmd`, `Cmd+Shift+3` or `Cmd+Shift+4` would take a screenshot instead.

**dwm-mac** uses the following keyboard shortcuts:

| Shortcut   | Function      | Changed?  |
|:---------- |:-------------:| -----:|
| Cmd+W      | Kill client   | Yes |
| Cmd+Shift+W      | Quit Xquartz      |   Yes |
| Cmd+H/L | Increase/decrease master window      |    No |
| Cmd+J/K      | Change focus      |   No |
| Cmd+[Number]      | Tag window with tag [Number]      |   Yes |
| Cmd+Ctrl+[Number]      | Change tag space to [number]      |   Yes |
| tbc. | | |

* * *

By default, **dwm-mac** uses a patched *artwiz cure* font to display some nice icons in the statusbar. However, you can change the following line to any font you want:

    static const char font[] = "-artwiz-cure-medium-*-*-*-11-*-*-*-*-*-iso8859-*";

Use `xfontsel` to get the name of the font you want to use.

Using Apple's Xquartz, there is a small modification you need to make to get icons in the statusbar: The patched artwiz cure font is selected by specifying an `iso8859-1` encoding, though you probably want Xquartz to use `UTF-8` encoding. However, running any `dwm` in Xquartz won't be able to display special glyphs in that way. That's why you need to start `dwm-mac` like this (put this into your `.xinitrc` or any other script that launches `dwm-mac`):

    LANG=en_US.iso8859-1 exec /usr/local/bin/dwm

You can look at my [dotfiles](https://github.com/Eroica/dotfiles) to get an idea of how I run `dwm-mac` on my machine.

* * *

If you are new to Xquartz on OS X, here is some additional information to get you started with Xquartz and `dwm-mac`:

* First, open Xquartz's preferences (select `X11` - `Preferences`).
* On the "Input" tab, make sure that the 2nd lowest option **is not selected**. This is an option that should be enabled for some legacy apps (for instance, `emacs`) that depend on a `Meta` key. If you check this option, you won't be able to type special characters such as `@` because the `Mode_switch` key (Apple's `Option` key) will be replaced by `Meta`.
    * If you really need a `Meta` key, you could use `xmodmap` to turn another key into `Meta`.
* On the "Output" tab, you can choose to run Xquartz as a fullscreen application. Keep in mind however that this is not the same kind of fullscreen apps that are famous since OS X Lion. Instead, Xquartz will not be visible until you press `Cmt+Option+A`. If you `Cmd+Tab` out of Xquartz and back into it, you would have to press this shortcut again. Because of this clunky behaviour, it's best to leave this option unchecked.
    * In general, it's best to go back to Xquartz by clicking on its dock icon instead of `Cmd+Tab`bing to it. (Ignore this line if you are already running Xquartz's latest beta version.)
    * There is some interesting behaviour you can achieve though--imagine you have a half-screen sized browser window open to your right, while `vim` is opened in `dwm-mac`. If you switch back into Xquartz using `Cmd+Tab` or by pressing its dock icon, Xquartz will get full focus again and will probably overlap your browser window. If you need the browser window on your side to write something in `vim`, just click into `vim`'s window to focus it, however the browser window will not lose focus and won't be overlapped!
* When running `xterm` or other commandline apps, copy text by **pressing and holding** the *right mouse button* to select some text, and **press** the *middle mouse button* once to paste something.

* * *
