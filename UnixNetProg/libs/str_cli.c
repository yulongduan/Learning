/***********************************************
 @fileName:     str_cli.c
 @description:  
 @author:       duanyulong
 @createdTime:  Sun 11 Sep 2016 01:22:35 PM CST
 @e-mail:       1175927052@qq.com

***********************************************/
#include "unp.h"

void str_cli(FILE * fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];

	while (Fgets(sendline, MAXLINE, fp) != NULL)
	{
		Write(sockfd, sendline, strlen);
		if(Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli: server terminated prematurely");

		Fputs(recvline, stdout);
	}
}
