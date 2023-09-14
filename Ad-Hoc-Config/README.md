# Ad Hoc Guide

Hi Barbie!

This is a guide made by 1/c Sierra Barbee about how to configure the RoboBoat to run an Ad Hoc Network. I will be splitting this up into different sections for ease of reading/understanding for future members of the Capstone project

## Laptop Host

### Establishing Baseline

Before you can start configuring your network you need to know what type of interface you are working with. If you are using the laptop that 2023 RoboBoat was using it should show the same if not similar information as what will be shown later. The first command you need to run is `iw dev`. When you do that it should look like this:
![Start point](https://github.com/DarkAngelRed/RoboBoat_Cyber_Minority/blob/main/Ad-Hoc-Config/host_inital_iw_dev_results.png)

`iw` Documentation if you get lost: [here](https://www.freedesktop.org/software/systemd/man/systemd.net-naming-scheme.html)

As shown above the interface being used is a wireless LAN on-board. This is like a wireless LAN except for the fact that it uses `ID_NET_NAME_ONBOARD' which involves predictive naming schemes which can be read about [here](https://www.freedesktop.org/software/systemd/man/systemd.net-naming-scheme.html).

Another thing that should be checked in the picture above is the mode being ran. If while you are starting this processes and in `iw dev` in the `wlo1` section the `type: managed` you are in the correct section and once you have familarized your starting point and feel comfortable you can move on to the next section.

### Changing into Ad Hoc mode

**BEFORE YOU DO ANYTHING RUN THIS:** `sudo systemctl stop NetworkManager`. If you don't do this then you **will not** be able to configure the interface.
