#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int Count = 0;
void* thread_main(void *arg);

int main(int argc,char* argv[]){
    for(int i=1;i<=2;++i){
        pthread_t t_id;
        int thread_param = 5;
        if(pthread_create(&t_id,NULL,thread_main,(void*)&thread_param) != 0){
            fprintf(stderr,"pthread_create() error\n");
            return -1;
        }
    }
    pthread_join();
	return 0;
}

void* thread_main(void* arg){
    pthread_detach(pthread_self());
    fprintf(stdout,"no.%d thread\n",++Count);

	return NULL;
}
