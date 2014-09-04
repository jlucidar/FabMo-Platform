#! /bin/sh

echo "/*************** script optimised for ArchLinuxARM-2014.04-rpi **************/"

echo "\tconnect the beaglebone to the internet via the ethernet cable,\n
\tlaunch the script\n
\tand go drink a coffee !\n\n
press a key to continue ..."
read pause


#time
pacman -S ntpd --noconfirm

#install the required packages for wifi support
pacman -S iw --noconfirm
pacman -S wireless_tools --noconfirm

# install gcc
pacman -S gcc --noconfirm

# install the dhcp server
pacman -S dhcp --noconfirm
pacman -S udhcpd --noconfirm

# install node.js
pacman -S nodejs --noconfirm

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




################ ETHERNET ON USB CONFIG #########################

# allow ethernet over usb at the startup 
echo "g_ether" >  /etc/modules-load.d/g_ether.conf


# mount the usb0 interface if it is available, and configure it with the ip 192.168.10.1, netmask 255.255.255.252
cat >> /etc/netctl/usb0 <<EOF
Description='A basic dhcp ethernet over usb connection'
Interface=usb0
Connection=ethernet
IP=static
Address=('192.168.10.1/29')
EOF

#enable at startup
netctl enable usb0


# dhcpd.conf
cat >> /etc/dhcpd.conf <<EOF
subnet 192.168.10.0 netmask 255.255.255.248 {
  range 192.168.10.2 192.168.10.6;
  default-lease-time 600;
  max-lease-time 7200;
}
EOF

# usb0 dhcp service
cat >>  /etc/systemd/system/dhcpd_usb0.service <<EOF
[Unit]
Description=IPv4 DHCP server on usb0
Wants=network.target
After=network.target

[Service]
Type=forking
PIDFile=/run/dhcpd4.pid
ExecStart=/usr/bin/dhcpd -4 -q -pf /run/dhcpd4.pid usb0
KillSignal=SIGINT

[Install]
WantedBy=multi-user.target
EOF

#enable dhcp on usb
systemctl enable dhcpd_usb0


# usb hotplug
cat > /etc/udev/rules.d/73-beaglebone.rules <<EOF
ACTION=="add", SUBSYSTEM=="usb", ENV{DEVTYPE}=="usb_interface", \
        ATTRS{idVendor}=="0403", ATTRS{idProduct}=="a6d0", \
        DRIVER=="", RUN+="/sbin/modprobe -b ftdi_sio"

ACTION=="add", SUBSYSTEM=="drivers", \
        ENV{DEVPATH}=="/bus/usb-serial/drivers/ftdi_sio", \
        ATTR{new_id}="0403 a6d0"

ACTION=="add", KERNEL=="ttyUSB*", \
	ATTRS{interface}=="BeagleBone", \
        ATTRS{bInterfaceNumber}=="00", \
	SYMLINK+="beaglebone-jtag"

ACTION=="add", KERNEL=="ttyUSB*", \
	ATTRS{interface}=="BeagleBone", \
        ATTRS{bInterfaceNumber}=="01", \
	SYMLINK+="beaglebone-serial"
EOF

# reload udev rules
udevadm control --reload-rules
##################################################################



############# TO-DO #################
# ADD THE dhcp server configuration #
#for the Wifi Direct connection	    #
#####################################

echo "end of the configuration ! reboot . . ."
sleep 2
reboot


