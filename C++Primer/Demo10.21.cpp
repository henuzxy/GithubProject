/*************************************************************************
	> File Name: Demo10.21.cpp
	> Author:henuzxy 
	> Mail: 
	> Created Time: Mon 29 Jul 2019 07:41:15 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int v = 5;
    auto f = [&v]()mutable ->bool {
        if(v == 0)
            return true;
        else{
            --v;
            return false;
        }
    };

    while(!f()){
        cout << "time ---" << endl;
    }
    return 0;
}
