#! /bin/sh
# require udhcp working for android
wpa_cli -i wlan1 p2p_find
wpa_cli -i wlan1 p2p_group_add
wpa_cli -i wlan1 wps_pin any 12345678
