/*************************************************************************
	> File Name: wait.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 17时30分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[]){
    int status;
    pid_t pid = fork();

    if(pid == 0){
        return 3;
    }
    else{
        fprintf(stdout,"Child PID: %d\n",pid);
        pid = fork();
        if(pid == 0){
            exit(4);
        }
        else{
            fprintf(stdout,"Child PID: %d\n",pid);
            wait(&status);
            if(WIFEXITED(status))
                fprintf(stdout,"Child send:%d\n",WEXITSTATUS(status));
            fprintf(stdout,"status = %d\n",status); 
            wait(&status);
            if(WIFEXITED(status))
                fprintf(stdout,"Child send:%d\n",WEXITSTATUS(status));
            sleep(20);
        }
    }
    return 0;
}
