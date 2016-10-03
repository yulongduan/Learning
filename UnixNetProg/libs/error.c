/***********************************************
 @fileName:     error.c
 @description:  
 @author:       duanyulong
 @createdTime:  Sun 11 Sep 2016 01:57:49 PM CST
 @e-mail:       1175927052@qq.com

***********************************************/
#include "unp.h"
#include <stdarg.h>
#include <syslog.h>

void err_sys(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, LOG_ERR, fmt, ap);
	va_end(ap);
	exit(1);
}

static void err_doit(int errnoflag, int level, const char *fmt, va_list ap)
{
	int error_save, n;
	char buf[MAXLINE + 1];

	error_save = errno;
#ifdef HAVE_VSNPRINTF
	vsnprintf(buf, MAXLINE, fmt, ap);
#else
	vsprintf(buf, fmt, ap);
#endif
	n = strlen(buf);
	if (errnoflag)
		snprintf(buf + n, MAXLINE - n, ":%s", strerror(errno_save));
	strcat(buf, "\n");

	if (daemon_proc)
	{
		syslog(level, buf);
	} else {
		fflush(stdout);
		fputs(buf, stderr);
		fflush(stderr);
	}
	return;
}
