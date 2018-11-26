#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5000
#define PORT 8080

void chat(int sockfd)
{
	char buff[SIZE];
	int n;
	for(;;)
	{
		bzero(buff,SIZE);
		read(sockfd,buff,sizeof(buff));
		if(strncmp("exit",buff,4)==0)
		{
			printf("Client Exited\n");
			break;
		}
		printf("Client: %s\n To client : ",buff);
		bzero(buff,SIZE);
		n=0;
		while((buff[n++]=getchar())!='\n');
		write(sockfd,buff,sizeof(buff));	
		if(strncmp("exit",buff,4)==0)
		{
			printf("Server Exited\n");
			break;
		}
	}
}
void main()
{
	int sockfd,conn,len;
	struct sockaddr_in addr,client_addr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("Socket creation failed\n");
		exit(0);
	}
	else
		printf("Socket successfully created\n");
		
			bzero(&addr,sizeof(addr));
			addr.sin_family=AF_INET;
			addr.sin_addr.s_addr=htonl(INADDR_ANY);
			addr.sin_port=htons(PORT);
		
		if((bind(sockfd,(struct sockaddr *)&addr, sizeof(addr)))!=0)
		{
			printf("Socket bind failed\n");
			exit(0);
		}
		else
			printf("Socket binded\n");
			
		
		if((listen(sockfd,5))!=0)
		{
			printf("Listen failed...\n");
			exit(0);
		}
		else
			printf("Waiting for connection\n");


		len=sizeof(client_addr);
		conn=accept(sockfd,(struct sockaddr *)&client_addr,&len);
		if(conn<0)
		{
			printf("Server acccept failed\n");
			exit(0);
		}
		else
			printf("Server acccept the client\n");
		chat(conn);
		close(sockfd);
}
