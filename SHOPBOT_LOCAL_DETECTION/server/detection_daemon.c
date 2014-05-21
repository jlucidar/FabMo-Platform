//Serveur
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
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
	
	char my_hostname[128];
	FILE *fp;
	char path[1035],result[1035] ;

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

			  // Return a json array with the network informations
		          /* SYNTAX :


			// { "hostname" : "value_of_hostname" ,
			//"networks":
			//	[
			//	  {"ip_adress": "value_of_ip_adress_1","interface": "name of interface_1},
			//	  {"ip_adress": "value_of_ip_adress_2","interface": "name of interface_2"},
			//	  ...
			//	]
			// }
			  */
			strcpy(result,""); // reset json string


			/***********************************************************************/
			/********************** start json string ******************************/
			/***********************************************************************/
			strcat(result,"{");
			/***********************************************************************/
			/*************** get hostname and format to json ***********************/	
			gethostname(my_hostname, sizeof my_hostname);
			strcat(result,"\"hostname\" : \"");
			strcat(result,my_hostname);			
			strcat(result,"\",");
			/***********************************************************************/			
			/*************** get networks and format to json ***********************/
			strcat(result,"\"networks\":");
			fp = popen("ip addr show | grep \"inet \"  | grep -v \" lo\" | awk  -F \" \" '{print $2 $NF}' | sed -e 's@/[0-9]\\{1,2\\}@\" , \"interface\" : \"@g' -e 's/.*/'\"{\\\"ip_address\\\" : \\\"\"'&/' -e 's/$/\"},/' -e '$ s@.$@]@' -e '1s/^/[/' | tr '\\n' ' '","r");
			if (fp == NULL) {
				printf("Failed to run command\n" );
			  	exit;
			}
			/* Read the output a line at a time - output it. */
			while (fgets(path, sizeof(path)-1, fp) != NULL) {
				strcat(result,path);
			}
			/* close */
			pclose(fp);
			/***********************************************************************/
			/********************** finish json string *****************************/
			strcat(result,"}");
			/***********************************************************************/
			/***********************************************************************/
			/***********************************************************************/
			
			//printf("%s\n", result);
			CHECK(sendto(sock,result,strlen(result)+1,0,(struct sockaddr*)&client,cltlen),"failed sending request");
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


