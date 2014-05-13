#! /bin/sh
# require udhcp working for android
wpa_cli p2p_find
wpa_cli p2p_group_add
wps_pin any 12345678
