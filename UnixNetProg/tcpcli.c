/***********************************************
 @fileName:     tcpcli.c
 @description:  
 @author:       duanyulong
 @createdTime:  Sun 11 Sep 2016 12:24:52 PM CST
 @e-mail:       1175927052@qq.com

***********************************************/
#include "lib/unp.h"

int main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;

	sockfd = Socket(AF_INET, SOCK_STRAM, 0);

	bzero(servaddr, sizeof());
	servaddr.sin_family = AF_INET;
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	Connect(sockfd, (sockaddr *) &servaddr, sizeof(servaddr));
	str_cli(stdin,sockfd);
	exit(0);
}
