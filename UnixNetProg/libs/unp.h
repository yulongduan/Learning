#ifndef __unp_h
#define __unp_h

#include <sys/socket.h> /*basic socket definations*/
#include <netinet/in.h> /* sockaddr_in{} and other internet definations */

void Accept(int, const struct sockaddr *, socklen_t *);
void Bind(int, const struct sockaddr *, socklen_t);
void Connect(int, const struct sockaddr *, socklen_t);
void Listen(int, int);

#endif


