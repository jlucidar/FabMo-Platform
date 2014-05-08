#!/bin/bash

###############################################
# This script create a port forward on your   #
# router if the upnp function is active on it.#
# the public port will be save in the global  #
# variable $UPNPC_PUBLIC_PORT.		      #
###############################################

execPath=$(dirname $0)


#remove last port forwarding : from 77XX
UPNPC_PUBLIC_PORT=`cat  $execPath/UPNPC_PUBLIC_PORT.dat`
upnpc -d $UPNPC_PUBLIC_PORT TCP > /dev/null 2>&1
rm $execPath/UPNPC_PUBLIC_PORT.dat > /dev/null 2>&1

#add a port forwarding : from 77XX to $ip:80
ip=`upnpc -l | grep "Local LAN ip address" | cut -d" " -f6`

public_port=$(( 7700+( $(od -An -N2 -i /dev/random) )%(100) ))


`upnpc -a $ip 22 $public_port TCP >/dev/null 2>&1`

$is_success=`upnpc -l | grep "TCP  $public_port->$ip:22" | wc -l >/dev/null 2>&1`
if [ $is_success -eq 1 ]
then
	UPNPC_PUBLIC_PORT=$public_port
	echo "port forwarding succcessful on port $UPNPC_PUBLIC_PORT"
	echo $UPNPC_PUBLIC_PORT > $execPath/UPNPC_PUBLIC_PORT.dat
else	
	echo "no upnp router available..."
fi


