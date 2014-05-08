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

execPath=$(dirname $0)


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

# delete the former ssh_tunnel if there is one
kill `cat $execPath/SSH_TUNNEL_PID.dat` >/dev/null 2>&1
rm $execPath/SSH_TUNNEL_PID.dat >/dev/null 2>&1



local_port=$(( 5500+( $(od -An -N2 -i /dev/random) )%(100) ))
user_at_distant_public_ip=$1
distant_public_port=$2

# set the ssh tunnel for accessing the web server on the raspberry pi from everywhere

ssh -f -N -L :$local_port:localhost:80 $user_at_distant_public_ip -p $distant_public_port
if [ $? -eq 0 ]
then
	ps aux | grep "[s]sh -f -N -L :$local_port:localhost:80 $user_at_distant_public_ip -p $distant_public_port" | awk -F " " '{ print $2 }' > $execPath/SSH_TUNNEL_PID.dat
	echo "SSH tunnel opened on localhost:$local_port"
else
	echo "ssh error : cannot open the tunnel"

fi
