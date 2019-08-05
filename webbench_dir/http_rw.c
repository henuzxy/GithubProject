/*************************************************************************
	> File Name: http_rw.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 17时10分42秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include "socket.c"

#define BUF_SIZE (2048)
#define true (1)
int main(int argc,char *argv[]){
    char request[BUF_SIZE] = "OPTIONS / HTTP/1.1\r\nHost: www.baidu.com\r\n\r\n";
    fprintf(stdout,"request:\n%s\n",request);
    int port = 80;
    int sock = my_socket(argv[1],port);
    write(sock,request,strlen(request));
    fprintf(stdout,"sock = %d\n",sock);
    if(sock <= 0){
        fprintf(stderr,"Error\n");
        return 1;
    }  
    char buf[BUF_SIZE];
    while(true){
        int len = read(sock,buf,BUF_SIZE);
        if(len == 0)
            break;
        else
            fprintf(stdout,"%s",buf);
    }
    return 0;
}

