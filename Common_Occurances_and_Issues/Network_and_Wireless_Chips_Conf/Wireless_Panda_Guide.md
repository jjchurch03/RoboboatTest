# Panda Wireless Guide

This guide is to help you set up and configure Panda Wireless chip

## Packages needed before staring

`sudo apt install flex`
`sudo apt install bison`
`sudo apt install net-tools`
`sudo apt install wpagui`

## Chip Specs

In case this guide is looked at in the future this is for the Panda Wireless PAU06 and guide is meant for an Ubuntu system (22.04).


## Checking specs

Use the command `lsusb`

While there may be different devices connected to the computer that is being used there should be a device attached called `Ralink Technology, Corp. RT5372 Wireless Adapter` as shown in the picture below:


If it does not show up the chip is dead and you will need to find a solution/alternative to this

## Compile and install Linux Driver for Panda Wireless N adapter on Fedora

Fedora Download Link: 
http://www.pandawireless.com/download/LinuxDriver4Fedora_v2.5.0.3.tar.bz2

**WARNING** This is a very old file and will require extra steps to get this set up than what general guidance will tell you. This Fedora file is *old*

- This is due to the fact that the supported kernels are linux kernel 2.4 and 2.6 series and by running `uname -r` you will find out you are in series 6.2 or later

*RUN EVERY COMMAND WITH ROOT/SUDO PRIVLEDGES*

### Blacklist RT2800 wireless module in the Linux Kernel

`cd /etc/modprobe.d`

`sudo nano blacklist.conf`

From here go to the bottom of this file and add this: 

### Copy RT2870STA to /etc 

RT2870STA.dat is located in your driver install directory

`sudo mkdir -p Wireless/RT2870STA` (under /etc directory)

`sudo cp /route/to/RT2870STA.dat /etc/Wireless/RT2870STA/RT2870STA.dat`

### Create tftpboot directory under root directory

Make sure you are in the root directory

If you are unsure run `cd ..` until you can't no more

`sudo mkdir /tfpboot`

### Compile the driver for the Panda Wireless N adapter

`cd` into where the download is stored

Run `tar jxvf LinuxDriver4Fedora_v2.5.0.3.tar.bz2`

From here go into the `cd LinuxDriver4Fedora_v2.5.0.3.tar.bz2`

Read the `README_STA_usb` file to understand Fedora files and what needs to be changed

*Before you do anything make sure you have flex and bison installed onto you system*

Current Problem: 
```sudo make
[sudo] password for barbees: 
make -C tools
make[1]: Entering directory '/home/barbees/Downloads/LinuxDriver4Fedora_v2.5.0.3/tools'
gcc -g bin2h.c -o bin2h
make[1]: Leaving directory '/home/barbees/Downloads/LinuxDriver4Fedora_v2.5.0.3/tools'
/home/barbees/Downloads/LinuxDriver4Fedora_v2.5.0.3/tools/bin2h
cp -f os/linux/Makefile.6 /home/barbees/Downloads/LinuxDriver4Fedora_v2.5.0.3/os/linux/Makefile
make -C /lib/modules/6.2.6-76060206-generic/build SUBDIRS=/home/barbees/Downloads/LinuxDriver4Fedora_v2.5.0.3/os/linux modules
make[1]: Entering directory '/usr/src/linux-headers-6.2.6-76060206-generic'
make[2]: *** No rule to make target 'arch/x86/entry/syscalls/syscall_32.tbl', needed by 'arch/x86/include/generated/uapi/asm/unistd_32.h'.  Stop.
make[1]: *** [arch/x86/Makefile:248: archheaders] Error 2
make[1]: Leaving directory '/usr/src/linux-headers-6.2.6-76060206-generic
make: *** [Makefile:357: LINUX] Error 2``

Current Solution

FIX KERNEL BECAUSE `syscall_32.tbl` is missing. 

Solution: Frankenstien's kernel

https://phoenixnap.com/kb/build-linux-kernel

Go to the website above and follow the directions in order to build your own up to date kernel
- This will take a long time so plan accordingly (constant connection and power supply will make it quicker)

### Finding the .ko file


