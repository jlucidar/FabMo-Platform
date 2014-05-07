#! /bin/sh

###############################################
# Open a SSH tunnel between you and the       #
# Rasp Pi Web Server.			      #
# you need to configure your router for port  #
# forwarding, or have run the upnpc script    #
# on the Rasp Pi before.                      #
# you must provide the public adress and port #
# of your device to make it work.             #
# Return the local port of the tunnel.        #
###############################################

if [ "$1" = "" ]
then 
echo "syntax : connect_distant.sh ip_adress port"
exit
fi

if [ "$2" = "" ]
then
echo "syntax : connect_distant.sh ip_adress port"
exit
fi

if [ "$3" != "" ]
then
echo "syntax : connect_distant.sh ip_adress port"
exit
fi

local_port=$(( 5500+( $(od -An -N2 -i /dev/random) )%(100) ))
distant_public_ip=$1
distant_public_port=$2

# set the ssh tunnel for accessing the web server on the raspberry pi from everywhere

ssh -f -N -L :$local_port:localhost:80 handibot-dev@$distant_public_ip -p $distant_public_port
if [ $? -eq 0 ]
then
echo $local_port 
fi
