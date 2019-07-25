/*************************************************************************
	> File Name: signal_remove_zombie.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 17时26分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void read_child_send(int sig){
    int status;
    pid_t pid = waitpid(-1,&status,WNOHANG);
    if(WIFEXITED(status)){
        fprintf(stdout,"Removed PID:%d\n",pid);
        fprintf(stdout,"Child send:%d\n",WEXITSTATUS(status));
    }
}

int main(int argc,char *argv[]){
    pid_t pid;
    struct sigaction act;
    act.sa_handler = &read_child_send;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD,&act,0);

    pid = fork();

    if(pid == 0){
        fprintf(stdout,"Child process running.\n");
        return 2;
    }
    else{
        fprintf(stdout,"Child process PID:%d\n",pid);
        pid = fork();
        
        if(pid == 0){
            fprintf(stdout,"Child process running.\n");
            return 3;
        }
        else{
            fprintf(stdout,"Child process PID:%d\n",pid);
            for(int i=0;i<3;++i){
                fprintf(stdout,"wait...\n");
                sleep(2);
            }
        }
    }
    return 0;
}
