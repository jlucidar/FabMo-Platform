#!/bin/bash

###############################################
# This script create a port forward on your   #
# router if the upnp function is active on it.#
# the public port will be save in the global  #
# variable $UPNPC_PUBLIC_PORT.		      #
###############################################


#remove last port forwarding : from 77XX
upnpc -d $UPNPC_PUBLIC_PORT TCP > /dev/null 2>&1
export UPNPC_PUBLIC_PORT=""

#add a port forwarding : from 77XX to $ip:80
ip=` upnpc -l | grep "Local LAN ip address" | cut -d: -f2`

public_port=$(( 7700+( $(od -An -N2 -i /dev/random) )%(100) ))


upnpc -a $ip 22 $public_port TCP >/dev/null 2>&1

if [ $? -eq 0 ]
then
	UPNPC_PUBLIC_PORT=$public_port
	export UPNPC_PUBLIC_PORT
	echo "port forwarding succcessful on port $UPNPC_PUBLIC_PORT"
else	
	echo $?
	echo "no upnp router available..."
fi


