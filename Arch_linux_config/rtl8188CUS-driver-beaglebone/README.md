driver for the rtl8188CUS chip on the beaglebone running Arch-Linux
===========
** NOT RECOGNIZE BY NL80211 YET **
** 	     BE CARREFUL        **

Install the drivers for the rtl8188CUS ( 8192cu ) on the beaglebone running ArchLinux without cross compiler, with p2p support and concurrence mode.

the concurrence mode allow you to use two wlan interface on a single chip ( wlan0 & wlan1 ).

It's usefull for making a wifi Direct connection without losing our normal connection, for exemple.



Troubles :
It seems to have a problem with nl80211 driver, so we cannot use the p2p functions yet, we cannot launch wpa_supplicant with nl80211 and the iw commands fail ( but not the iwconfig and iwpriv commands).



Instructions :
#	based on the tutorial found here : 
# http://www.codealpha.net/864/how-to-set-up-a-rtl8192cu-on-the-beaglebone-black-bbb/
#	and the drivers source from here :
# http://www.realtek.com.tw/downloads/downloadsView.aspx?Langid=1&PFid=48&Level=5&Conn=4&ProdID=277&DownTypeID=3&GetDown=false&Downloads=true#RTL8192CU

# TODO FIRST : Copy this folder into your /root/ folder on the beaglebone.

#compile the driver :

pacman -Syu
pacman -S linux-headers-am33x-legacy

cd /usr/src/kernel
make scripts
ln -s /usr/src/kernel /lib/modules/$(uname -r)/build
cd ~/rtl8188CUS-driver-beaglebone
make CROSS_COMPILE=""

#install the driver :
mv 8192cu.ko /lib/modules/$(uname -r)
depmod -a
cd /etc/modules-load.d
echo "8192cu" > rtl8192cu-vendor.conf

#blacklist the old drivers :
cd /etc/modprobe.d
echo "install rtl8192cu /bin/false" >wifi_blacklist.conf
echo "install rtl8192c_common /bin/false" >>wifi_blacklist.conf
echo "install rtlwifi /bin/false" >>wifi_blacklist.conf

