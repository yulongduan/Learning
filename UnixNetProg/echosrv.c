/***********************************************
 @fileName:     echosrv.c
 @description:  
 @author:       duanyulong
 @createdTime:  Sun 24 Jul 2016 05:24:20 PM CST
 @e-mail:       1175927052@qq.com

***********************************************/

#include <lib/unp.h>
int main(int argc, char** argv)
{
	int listenfd,connfd;
	struct sockaddr_in srvaddr, cliaddr;
	socket_len clilen;
	pid_t clild_pid;
	if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		ERROR_EXIT("create listen socket failed.");	
	}

	bzero(&srvaddr, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_addr.s_addr = htnol(INADDR_ANY);
	srvaddr.sin_port = htons(8888);

	if((bind(listenfd, sockaddr* &(srvaddr), sizeof(srvaddr))) == -1)
	{
		ERROR_EXIT("bind socket failed.");
	}

	if((listen(listenfd, 1024)) == -1)
	{
		ERROR_EXIT("listen failed.");
	}

	while(true)
	{
		clilen = sizeof(cliaddr);
		if((connfd == accept(listenfd, (sockaddr *) &cliaddr, &clilen)) == -1)
		{
			ERROR_EXIT("accpet connect failed.");
		}

		if ((clild_pid = fork()) == 0)
		{
			
		}
	}
}
