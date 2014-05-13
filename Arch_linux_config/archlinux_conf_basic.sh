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

# install the dhcp server
pacman -S dhcp --noconfirm
pacman -S udhcpd --noconfirm

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

# allow ethernet over usb at the startup 
echo "g_ether" >  /etc/modules-load.d/g_ether.conf
# mount the usb0 interface if it is available, and configure it with the ip 192.168.10.1, netmask 255.255.255.252
echo -e "Description='A basic dhcp ethernet over usb connection'\nInterface=usb0\nConnection=ethernet\nIP=static\nAddress=('192.168.10.1/29')" > /etc/netctl/usb0
#enable at startup
netctl enable usb0

#dhcp service on usb0

# dhcpd.conf\n
# usb0 dhcp service\n
echo -e "subnet 192.168.10.0 netmask 255.255.255.248 {\n  range 192.168.10.2 192.168.10.6;\n  default-lease-time 600;\n  max-lease-time 7200;\n}\n" > /etc/dhcpd.conf

echo -e "[Unit]\nDescription=IPv4 DHCP server on usb0\nWants=network.target\nAfter=network.target\n\n[Service]\nType=forking\nPIDFile=/run/dhcpd4.pid\nExecStart=/usr/bin/dhcpd -4 -q -pf /run/dhcpd4.pid usb0\nKillSignal=SIGINT\n\n[Install]\nWantedBy=multi-user.target\n" > /etc/systemd/system/dhcpd_usb0.service
systemctl enable dhcpd_usb0

############# TO-DO #################
# ADD THE dhcp server configuration #
#for the Wifi Direct connection	    #
#####################################

echo "end of the configuration ! reboot . . ."
sleep 2
reboot


