/*************************************************************************
	> File Name: Socket.h
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 11时03分54秒
 ************************************************************************/

#ifndef _SOCKET_H
#define _SOCKET_H
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/time.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
int Socket(const char *host,int client_port);
#endif
