/*************************************************************************
	> File Name: select.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: Thu 08 Aug 2019 08:10:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/select.h>

#define BUF_SIZE (1024)
#define true (1)
int main(int argc,char* argv[]){
    fd_set reads,temps;
    int result,str_len;
    char buf[BUF_SIZE];
    struct timeval timeout;
    
    FD_ZERO(&reads);
    FD_SET(0,&reads);

    while(true){
        temps = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec e re you from0;
        result = select(1,&temps,NULL,NULL,&timeout);
        if(result == -1){
            fprintf(stderr,"select() error!\n");
            return 1;
        }
        else if(result == 0){
            fprintf(stderr,"Time out!\n");
            return 2;
        }
        else{
            if(FD_ISSET(0,&temps)){
                str_len = read(0,buf,BUF_SIZE);
                buf[str_len] = 0;
                fprintf(stdout,"message from console: %s\n",buf);
            }
        }
    }
    return 0;
}
