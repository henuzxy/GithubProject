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
#include<netdb.h>
int main(int argc,char *argv[]){
    char *host = argv[1];
    struct hostent *ht = gethostbyname(host);
    fprintf(stdout,"%s\n",ht->h_name);
    fprintf(stdout,"%s\n",inet_ntoa(*(struct in_addr*)ht->h_addr_list[0]));
    return 0;
}
