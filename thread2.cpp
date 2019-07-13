#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
void* thread_main(void *arg);
int main(int argc,char *argv[]){
	pthread_t t_id;
	int thread_param = 5;
	void* thr_ret;
	if(pthread_create(&t_id,NULL,thread_main,(void*)&thread_param) != 0){
		fprintf(stderr,"pthread_create() error");
		return -1;
	}

	if(pthread_join(t_id,&thr_ret) != 0){
		fprintf(stdout,"pthread_join() error");
		return -1;
	}

	fprintf(stdout,"Thread return message: %s\n",(char*)thr_ret);
	free(thr_ret);
	return 0;
}

void* thread_main(void *arg){
	int cnt = *(int*)arg;
	char* message = (char*)malloc(sizeof(char)*64);
	strcpy(message,"hello,This is a Thread!");
	for(int i=0;i<cnt;++i){
		sleep(1);
		fprintf(stdout,"running thread\n");
	}
	return (void*)message;
}
