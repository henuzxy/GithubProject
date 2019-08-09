/*************************************************************************
	> File Name: echo_client.c
	> Author:henuzxy
	> Mail:1961714414@qq.com
	> Created Time: 2019年08月08日 星期四 23时28分03秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define BUF_SIZE (1024)
#define true (1)
#define false (0)
void error_handling(const char* msg);

int main(int argc,char* argv[]){
    int sock;
    char buf[BUF_SIZE];
    int str_len,recv_len,recv_cnt;
    struct sockaddr_in serv_adr;

    if(argc != 3){
        fprintf(stderr,"Usage: %s <IP> <Port>",argv[0]);
        exit(1);
    }

    sock = socket(PF_INET,SOCK_STREAM,0);
    if(sock == -1)
        error_handling("socket() error");
    memset(&serv_adr,0,sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    if(connect(sock,(struct sockaddr*)&serv_adr,sizeof(serv_adr)) == -1)
        error_handling("connect() error");
    else
        fprintf(stdout,"Connected...\n");
    while(true){
        fprintf(stdout,"input message(Q to quit):\n");
        fscanf(stdin,"%s",buf);
        if(!strcmp(buf,"Q") || !strcmp(buf,"q"))
            break;
        str_len = write(sock,buf,strlen(buf));
        
        recv_len = read(sock,buf,BUF_SIZE);
        fprintf(stdout,"message from sock:%s\n",buf);
    }
    close(sock);

    return 0;
}

void error_handling(const char* msg){
    fprintf(stderr,"%s\n",msg);
    exit(1);
}
