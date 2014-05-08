//Client

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CHECK(r,m) if((r)== SOCKET_ERROR ){printf("%s\n",m);exit(-1);}
#define MAXBUFF 1024
#define MESS "R U A SBT ?"
#define NAME "/tmp/sbt_r_u_a_sbt"

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

int main(int argc, char* argv[]){

	struct sockaddr_in server;
	struct timeval tv;
	int sock;
	char Buff[MAXBUFF];
	int siserv=sizeof(server);

	WSADATA wsa;

    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Initialising Winsock failed ...\n");
        return(-1);
    }

    if((sock = socket(AF_INET , SOCK_DGRAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
        exit(-1);
    }

	server.sin_family = AF_INET;
	server.sin_port = 7777; // port 7777
	if (argc > 1)
		server.sin_addr.s_addr = inet_addr(argv[1]);// server ip adress
	else
		{printf("need a ip adress\n");exit(-1);}


	tv.tv_sec = 2000;  /* 2 Sec Timeout */

	CHECK(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval)),"setsockopt");

	CHECK(sendto(sock,MESS,strlen(MESS),0,(struct sockaddr*)&server,siserv),"failed sending request");

    memset(Buff,'\0', MAXBUFF);
	CHECK(recvfrom(sock,Buff,MAXBUFF,0,(struct sockaddr*)&server,&siserv),"timeout");
	close(sock);
	exit(0);
}
