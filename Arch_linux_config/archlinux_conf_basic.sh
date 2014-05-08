#! /bin/sh

echo "/*************** script optimised for ArchLinuxARM-2014.04-rpi **************/"

echo "\tconnect the raspberry pi via the ethernet cable,\n
\tlaunch the script\n
\tand go drink a coffee !\n\n
press a key to continue ..."
read pause

## seems to do it by itself on the first launch
#connection over the ethernet network
#dhcpd
#wait for getting the ip
#sleep 5
# print the network configuration
#ifconfig eth0

#install the required packages for wifi support
pacman -S iw --noconfirm
pacman -S wireless_tools --noconfirm
pacman -S wicd --noconfirm

#install the automatic port forwarding
pacman -S miniupnpc --noconfirm

# install gcc
pacman -S gcc --noconfirm

# update the system
pacman -Syu --noconfirm

##### OPTIONAL #####
## install the little GUI interface xdle
#pacman -S xorg --noconfirm
#pacman -S xorg-xinit --noconfirm
#pacman -S lxde --noconfirm
## launch at the start-up the following : lxdm
#systemctl enable /lib/systemd/system/lxdm.service
####################

# launch at the start-up the following : wpa_supplicant, wifi auto manager
systemctl enable /lib/systemd/system/wpa_supplicant.service
systemctl enable netctl-auto@wlp2s0.service


echo "end of the configuration ! reboot . . ."
sleep 2
reboot


