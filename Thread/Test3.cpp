//C++11 锁实现线程同步
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex mu;
int sum = 0; 
void run1(){
    std::unique_lock<std::mutex> ul(mu);
    for(int i=0;i<1000000;++i){
        sum += 1;
    }
}
void run2(){
    std::unique_lock<std::mutex> ul(mu);
    for(int i=0;i<1000000;++i){
        sum += 1;
    }
}
int main(void){
    thread t1(run1);
    thread t2(run2);
    t1.join();
    t2.join();
    cout << "sum = " << sum << endl;


    return 0;
}