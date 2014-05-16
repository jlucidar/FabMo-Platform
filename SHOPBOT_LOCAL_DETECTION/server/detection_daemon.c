//Serveur
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHECK(r,m) if((r)<0){perror(m);exit(-1);}
#define MAXBUFF 1024
#define OK "YES I M !"
#define ERR "I DNT UNDRSTND !"
#define HOSTNAME "U NAME ?"
#define REQ "R U A SBT ?"


int main(){
	struct sockaddr_in client;
	int cltlen= sizeof(client);
	struct sockaddr_in server;
	int siserv=sizeof(server);
	int sock;
	char Buff[MAXBUFF];
	char adr_cli[20];
	char my_hostname[128];
	CHECK(sock=socket(AF_INET,SOCK_DGRAM,0),("problem with socket creation"));
	server.sin_family = AF_INET;
	server.sin_port = 7777;
	server.sin_addr.s_addr= htonl(INADDR_ANY); // receive on every interfaces
	
	CHECK(bind(sock,(struct sockaddr*)&server,sizeof(server)),"bind problem");
	while(1)
	{
		cltlen = sizeof(client);
		bzero(Buff,MAXBUFF);
		CHECK(recvfrom(sock,Buff,MAXBUFF,0,(struct sockaddr *)&client,&cltlen),"reception trouble");

		if(strcmp(Buff,REQ)==0)
		{
			printf("scan in progress...\n");
			CHECK(sendto(sock,OK,strlen(OK)+1,0,(struct sockaddr*)&client,cltlen),"failed sending request");
			//send OK
			// here it works ! ( UDP create a bidirectional channel)
		}
		else if(strcmp(Buff,HOSTNAME)==0)
		{
			printf("hostname request...\n");
			gethostname(my_hostname, sizeof my_hostname);
			CHECK(sendto(sock,my_hostname,strlen(my_hostname)+1,0,(struct sockaddr*)&client,cltlen),"failed sending request");
			//send OK
			// here it works ! ( UDP create a bidirectional channel)
		}
		else
		{
			CHECK(sendto(sock,ERR,strlen(ERR)+1,0,(struct sockaddr*)&client,cltlen),"failed sending request");
			//else send ERR
		}
		
	}
	close(sock);
	exit(0);
	}


