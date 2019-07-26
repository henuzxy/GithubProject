/*************************************************************************
	> File Name: pipe_demo01.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 17时55分05秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

#define BUF_SIZE (48)

int main(int argc,char *argv[]){
    int fds[2];
    char message[] = "hello,i'm child process.";
    char buf[BUF_SIZE];
    pid_t pid;
    if(pipe(fds) != 0){
        fprintf(stderr,"create pipe error!\n");
        return 2;
    }
    pid = fork();
    if(pid == 0){
        write(fds[1],message,sizeof(message));
    }
    else{
        read(fds[0],buf,BUF_SIZE);
        fprintf(stdout,"received message:%s\n",buf);
    }

    return 0;
}
