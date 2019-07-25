/*************************************************************************
	> File Name: signal.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 15时50分41秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void timeout(int sig){
    if(sig == SIGALRM)
        fprintf(stdout,"Time out!\n");
    alarm(2);
}
void keycontrol(int sig){
    if(sig == SIGINT)
        fprintf(stdout,"CTRL+C pressed!\n");
}
int main(int argc,char *argv[]){
    signal(SIGALRM,timeout);
    signal(SIGINT,keycontrol);
    alarm(2);
    
    for(int i=0;i<3;++i){
        fprintf(stdout,"wait...\n");
        sleep(20);
    }

    return 0;
}


