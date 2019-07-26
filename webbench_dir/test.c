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
int main(int argc,char *argv[]){
    
    fprintf(stdout,"SHUT_RD:%d\n",SHUT_RD);
    fprintf(stdout,"SHUT_WR:%d\n",SHUT_WR);
    fprintf(stdout,"SHUT_RDWR:%d\n",SHUT_RDWR);
    return 0;
}
