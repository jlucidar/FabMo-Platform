//Client
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CHECK(r,m) if((r)==-1){perror(m);exit(-1);}
#define MAXBUFF 1024
#define REQ "R U A SBT ?"
#define HOSTNAME "U NAME ?"
#define NAME "/tmp/sbt_r_u_a_sbt"

int main(int argc, char* argv[]){

	struct sockaddr_in server;
	struct timeval tv;
	int sock;
	char Buff[MAXBUFF];
	int siserv=sizeof(server);
	CHECK(sock=socket(AF_INET,SOCK_DGRAM,0),("problem with socket creation"));
	server.sin_family = AF_INET;
	server.sin_port = 7777; // port 7777
	if (argc > 1)
		server.sin_addr.s_addr = inet_addr(argv[1]);// server ip adress
	else
		{printf("need a ip adress\n");exit(-1);}
	

	tv.tv_sec = 2;  /* 2 Sec Timeout */
	tv.tv_usec = 0;  // Not init this can cause strange errors

	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));

	CHECK(sendto(sock,REQ,strlen(REQ)+1,0,(struct sockaddr*)&server,siserv),"failed sending request");

	CHECK(recvfrom(sock,Buff,MAXBUFF,0,(struct sockaddr*)&server,&siserv),"reception trouble");

	CHECK(sendto(sock,HOSTNAME,strlen(HOSTNAME)+1,0,(struct sockaddr*)&server,siserv),"failed sending request");

	CHECK(recvfrom(sock,Buff,MAXBUFF,0,(struct sockaddr*)&server,&siserv),"no hostname");
	printf("%s",Buff);
	close(sock);
	exit(0);
}
