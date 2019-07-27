/*************************************************************************
	> File Name: test.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月26日 星期五 15时35分38秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/socket.h>
#include "socket.c"
int main(int argc,char *argv[]){
    char host[] = "www.baidu.com";
    int port = 80;
    int sock = my_socket(host,port);
    fprintf(stdout,"test_sock = %d\n",sock);
    return 0;
}
