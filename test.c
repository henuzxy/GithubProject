/*************************************************************************
	> File Name: test.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月22日 星期一 16时20分42秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(int argc,char* argv[]){
    char host[] = "www.baidu.com";
    unsigned long inaddr;
    inaddr = inet_addr(host);
    if(inaddr == INADDR_NONE){
        fprintf(stdout,"YES\n"); 
    }
    else{
        fprintf(stdout,"NO\n");
    }
    return 0;
}
