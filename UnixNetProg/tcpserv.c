/***********************************************
 @fileName:     tcpserv.c
 @description:  
 @author:       duanyulong
 @createdTime:  Sun 11 Sep 2016 10:12:45 AM CST
 @e-mail:       1175927052@qq.com

***********************************************/
#include "lib/unp.h"

int main(int argc, char** argv) 
{
	int listenfd, connfd;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t clilen;
	pid_t childpid;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&srvaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	Bind(listenfd, (sockaddr *) &servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);

	while(true) 
	{
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (sockaddr *) &cliaddr, &clilen);
		if( (childpid = Fork()) == 0)
		{
			Close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}
}
