//两个线程交替打印0-100.
#include <iostream>
#include <condition_variable>
#include <thread>
bool flag = false;
std::mutex mu;
std::condition_variable cv;
int value = 0;
void run1(){
    while(value < 100){
        std::unique_lock<std::mutex> ul(mu);
        cv.wait(ul,[](){return flag;});
        std::cout << value << std::endl;
        value += 1;
        flag = false;
        cv.notify_one();
    }
}
void run2(){
    while(value < 100){
        std::unique_lock<std::mutex> ul(mu);
        cv.wait(ul,[](){return !flag;});
        std::cout << value << std::endl;
        value += 1;
        flag = true;
        cv.notify_one();
    }
}
int main(void){
    std::thread t1(run1);
    std::thread t2(run2);
    t1.join();
    t2.join();
    


    return 0;
}