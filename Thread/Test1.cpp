//两个线程交替打印0-100
#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <condition_variable>
using namespace std; 
mutex mu;
condition_variable cv;
bool flag =false;
void run1(){
    for(int i=1;i<=100;i+=2){
        unique_lock<mutex> ul(mu);
        while(flag == false){
            cv.wait(ul);
        }
        flag = false;
        cout << i << endl;
        cv.notify_one();
    }
}
void run2(){
    for(int i=0;i<=100;i+=2){
        unique_lock<mutex> ul(mu);
        while(flag == true){
            cv.wait(ul);
        }
        cout << i << endl;
        flag = true;
        cv.notify_one();
    }
}
int main(void){
    thread t1(run1);
    thread t2(run2);
    t1.join();
    t2.join();

    return 0;
}
