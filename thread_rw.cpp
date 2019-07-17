#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define buf_size (1024)
void *send_msg(void * arg);
void *recv_msg(void * arg);

int main(int argc,char* argv[]){

	pthread_t send_id,recv_id;
	pthread_create(&send_id,NULL,send_msg,NULL);
	pthread_create(&recv_id,NULL,recv_msg,NULL);

	void *send_ret,*recv_ret;
	pthread_join(send_id,&send_ret);
	pthread_join(recv_id,&recv_ret);
	return 0;
}

void *send_msg(void * arg){
	char buf[buf_size];
	while(true){
		fgets(buf,buf_size-1,stdin);
		if(!strcmp("q\n",buf) || !strcmp("Q\n",buf))
			break;
		printf("input: %s\n",buf);
	}
	return NULL;
}

void *recv_msg(void * arg){
	while(true){
		fprintf(stdout,"output: This is a test.\n");
		sleep(3);
	}
	return NULL;
}
