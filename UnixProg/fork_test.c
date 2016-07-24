/***********************************************
 @fileName:     fork_test.c
 @description:  
 @author:       duanyulong
 @createdTime:  Sun 24 Jul 2016 09:41:59 PM CST
 @e-mail:       1175927052@qq.com

***********************************************/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int agrc, char** argv)
{
	pid_t child_pid;
	if( (child_pid = fork()) == 0)
	{
		pid_t p_id = getppid();
		printf("my father id is %d", p_id);	
		exit(0);
	}
	pid_t id = getpid();
	printf("my id is %d", id);
	exit(0);
}
