#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define NUM_THREAD (100)

void* thread_inc(void* arg);
void* thread_des(void* arg);

long long num = 0;
pthread_mutex_t mutex;

int main(int argc,char* argv[]){
	pthread_t thread_id[NUM_THREAD];
	pthread_mutex_init(&mutex,NULL);
	int inc_param = 10000;
	int des_param = 10000/2;
	for(int i=0;i<NUM_THREAD;++i){
		if(i&1)
			pthread_create(thread_id+i,NULL,thread_inc,(void*)&inc_param);
		else
			pthread_create(thread_id+i,NULL,thread_des,(void*)&des_param);
	}

	for(int i=0;i<NUM_THREAD;++i)
		pthread_join(thread_id[i],NULL);
	
	fprintf(stdout,"result:%lld\n",num);
	pthread_mutex_destroy(&mutex);
	return 0;
}
void* thread_inc(void *arg){
	int len = *(int*)arg;
	pthread_mutex_lock(&mutex);
	for(int i=0;i<len;++i){
		num+=1;
	}
	pthread_mutex_unlock(&mutex);
	//这里扩大的临界区，把for也作为临界区的一部分了
	return NULL;
}
void* thread_des(void* arg){
	int len = *(int*)arg;
	for(int i=0;i<len;++i){
		pthread_mutex_lock(&mutex);
		num-=1;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
