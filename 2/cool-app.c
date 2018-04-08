/*
	C ECHO client example using sockets
*/
#define _GNU_SOURCE
#include<stdio.h>	//printf
#include<string.h>	//strlen
#include <unistd.h>
#include<sys/socket.h>	//socket
#include<arpa/inet.h>	//inet_addr

int main(int argc , char *argv[])
{
	int sock;
	struct sockaddr_in server;
	char server_reply[2048];
	char password[20] = "Sp4c3Invaders"; 
	char message[1024] = "Header: X-cool-app\nUser: Defaul\nPassword:";

	str = (char *)memfrob((void *)str, strlen(password));
	strcat(message, password);
	
	//Create socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");
	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8088 );

	//Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return 1;
	}
	
		
	//Send some data
	if(send(sock , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	
	//Receive a reply from the server
	if( recv(sock , server_reply , 2000 , 0) < 0)
	{
		puts("recv failed");
		return 1;
	}
	
	puts(server_reply);
	
	close(sock);
	return 0;
}
