/*************************************************************************
	> File Name: 318.cpp
	> Author:henuzxy 
	> Mail: 
	> Created Time: Mon 29 Jul 2019 04:23:10 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int main(int argc,char* argv[]){
    vector<int> vec;
    for(int i=1;i<=5;++i)
        vec.push_back(i);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    vec.reserve(3);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    return 0;
}
