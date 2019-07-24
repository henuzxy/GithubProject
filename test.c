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
#include<unistd.h>
int main(int argc,char* argv[]){
    pid_t pid = fork();
    if(pid == 0){
        pid = fork();
        if(pid == 0){
            fprintf(stdout,"子进程的子进程");
        }
        else{
            fprintf(stdout,"子进程子进程:%d\n",pid);
        }
    }
    else{
        fprintf(stdout,"子进程:%d\n",pid);
    }
    return 0;
}
