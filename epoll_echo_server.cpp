#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#define BUF_SIZE 1024
#define EPOLL_SIZE 50
void error_handling(const char *message);
int main(int argc,char *argv[]){
	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t addr_sz;
	char buf[BUF_SIZE];
	int str_len,i;
	
	struct epoll_event *ep_events;
	struct epoll_event event;
	int epfd,event_cnt;
	if(argc != 2){
		printf("Usage :%s <port>\n",argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET,SOCK_STREAM,0);
	if(serv_sock == -1)
		error_handling("socket() error");
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock,(struct sockaddr*) &serv_addr,sizeof(serv_addr)) == -1)
		error_handling("bind() error");
	if(listen(serv_sock,5) == -1)
		error_handling("listen() error");
	epfd = epoll_create(EPOLL_SIZE);
	ep_events = (epoll_event*)malloc(sizeof(struct epoll_event)*EPOLL_SIZE);

	event.events = EPOLLIN;
	event.data.fd = serv_sock;
	epoll_ctl(epfd,EPOLL_CTL_ADD,serv_sock,&event);

	while(true){
		event_cnt = epoll_wait(epfd,ep_events,EPOLL_SIZE,-1);
		//这里ep_events 是存放发生事件的文件描述符。扫描的依然是epfd这个文件
		if(event_cnt == -1){
			puts("epoll_wait() error");
			break;
		}
		for(i=0;i<event_cnt;++i){
			if(ep_events[i].data.fd == serv_sock){
				addr_sz = sizeof(clnt_addr);
				clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&addr_sz);
				event.events = EPOLLIN;
				event.data.fd = clnt_sock;
				epoll_ctl(epfd,EPOLL_CTL_ADD,clnt_sock,&event);
				printf("connected client:%d\n",clnt_sock);
			}
			else{
				str_len = read(ep_events[i].data.fd,buf,BUF_SIZE);
				if(str_len == 0){
					epoll_ctl(epfd,EPOLL_CTL_DEL,ep_events[i].data.fd,NULL);
					close(ep_events[i].data.fd);
					printf("closed client:%d\n",ep_events[i].data.fd);
				}
				else{
					write(ep_events[i].data.fd,buf,str_len);
				}
			}
		}
	}
	close(serv_sock);
	close(epfd);
	return 0;
}
void error_handling(const char *message){
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}
