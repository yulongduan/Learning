/***********************************************
 @fileName:     str_echo.c
 @description:  
 @author:       duanyulong
 @createdTime:  Sun 11 Sep 2016 01:49:28 PM CST
 @e-mail:       1175927052@qq.com

***********************************************/
#include "unp.h"

void str_echo(int sockfd)
{
	ssize_t n;
	char buf[MAXLINE];

again:
	while( (n = read(sockfd, buf, MAXLINE)) > 0)
		Writen(sockfd, buf, n);

	if(n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		err_sys("str_echo: read error");
}
