#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 5000
#define PORT 8080
//#define SA struct sockaddr
void chat(int sockfd)
{
	char buff[SIZE];
	int n;
	for(;;)
	{
		bzero(buff,sizeof(buff));
		printf("Enter the string : ");
		n=0;
		while((buff[n++]=getchar())!='\n');
		write(sockfd,buff,sizeof(buff));
		if((strncmp(buff,"exit",4))==0)
		{
			printf("Server Exited\n");
			break;
		}

		bzero(buff,sizeof(buff));
		
		read(sockfd,buff,sizeof(buff));
		
		printf("Server : %s",buff);
		if((strncmp(buff,"exit",4))==0)
		{
			printf("Client Exited\n");
			break;
		}
	}
}

int main(int argc, char**argv) 
{
	int sockfd,conn;
	struct sockaddr_in addr,cli;
	char *serverAdd;

	 if (argc < 2) 
	{  
	      printf("Please enter as ./cli < IP address >\n");  
	      exit(1);    
     	}  
      
     	serverAdd = argv[1];  

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	if(sockfd==-1)
	{
		printf("Socket creation failed\n");
		exit(0);
	}
	else
		printf("Socket created\n");
	
	bzero(&addr,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(PORT);
	addr.sin_addr.s_addr=inet_addr(serverAdd);

	if(connect(sockfd,(struct sockaddr *)&addr,sizeof(addr))!=0)
	{
		printf("Connection with the server failed\n");
		exit(0);
	}
	else
		printf("Connected to the server\n");
	chat(sockfd);
	close(sockfd);
}
