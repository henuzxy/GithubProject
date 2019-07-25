/*************************************************************************
	> File Name: zombie.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 17时07分37秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    pid_t pid = fork();
    if(pid == 0){
        fprintf(stdout,"child process.\n");
    }
    else{
        fprintf(stdout,"child process ID:%d\n",pid);
        sleep(30);
    }
    if(pid == 0){
        fprintf(stdout,"End child process.\n");
    }
    else{
        fprintf(stdout,"End parent process.\n");
    }

    return 0;
}
