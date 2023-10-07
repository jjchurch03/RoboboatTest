# GUI_start_stop

These instructions work on an Ubuntu 22.04 machine. This guide will have to be changed as the group moved from OS to OS

For desktop users, having a GUI start automatically is a matter of convenience. However, it does consume a lot more system resources than simply booting into the command line and then starting the GUI manually if necessary. For servers, you almost always do not want to boot directly to GUI, as to minimize system overheard and boot time as much as possible.

## Stop the GUI

`sudo systemctl set-default multi-user`

From here either reboot the system or log out and this should get you to a terminal based system

If you want to do this via terminal use either `reboot` or`gnome-session-quit`

## Start the GUI

There are two ways to do this. One is on the boot and the other one is via the command line. Both require the command line so choose if you need it temporarily or more long term.

Long term (boot)
- `sudo systemctl set-default graphical`

Short term (terminal)
- `sudo systemctl start gdm3`
