//linux 下信号量实现线程同步
#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;
sem_t sem_one;
sem_t sem_two;
const int N = 10000;
int sum = 0; 
void run1(){
   
    for(int i=0;i<N;++i){
         sem_wait(&sem_two);//这种代价比较大
        sum += 1;
        //cout << "run1 : " << i << endl;
         sem_post(&sem_one);
    }
   
}
void run2(){
    
    for(int i=0;i<N;++i){
        sem_wait(&sem_one);
        sum += 1;
      //  cout << "run2 : " << i << endl;
        sem_post(&sem_two);
    }
    
}
int main(void){
    sem_init(&sem_one,0,0);
    sem_init(&sem_two,0,1);
    thread t1(run1);
    thread t2(run2);
    t1.join();
    t2.join();
    sem_destroy(&sem_one);
    sem_destroy(&sem_two);
    cout << "sum = " << sum << endl;


    return 0;
}
