/*************************************************************************
	> File Name: waitpid.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 14时02分15秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[]){
    int status;
    pid_t pid = fork();
    if(pid == 0){
        sleep(10);
        return 2;
    }
    else{
        while(!waitpid(-1,&status,WNOHANG)){
            sleep(1);
            fprintf(stdout,"sleep 1 sec.\n");
        }
        if(WIFEXITED(status))
            fprintf(stdout,"Child send:%d\n",WEXITSTATUS(status));
    }
    return 0;
}
