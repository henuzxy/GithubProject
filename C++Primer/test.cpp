/*************************************************************************
	> File Name: test.cpp
	> Author:henuzxy 
	> Mail: 
	> Created Time: Mon 29 Jul 2019 05:05:32 PM CST
 ************************************************************************/

#include<iostream>
#include<numeric>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(int argc,char* argv[]){
    /*
    auto f = []{return 3;};
    cout << f() << endl;

    auto f2 = [](const int A,const int B){if(A > B) return A;else return B;};
    cout << f2(1,2) << endl;
   
   */
    /*
    int a = 0;
    auto f3 = [&a](const int A){
        cout << "a = " << a << endl; 
        return a+A;};
    cout << f3(2) << endl;
    a = 100;
    cout << f3(2) << endl;

    vector<int> vec;
    auto f4 = [](vector<int> &v){
        for(int i=1;i<=5;++i)
            v.push_back(i);
    };
    auto f5 = [](const int &a){
        cout << a << " ";
    };
    f4(vec);
    for_each(vec.begin(),vec.end(),f5);
    int b = 10,c = 100;
    auto f6 = [=,&c]() -> void{
        cout << "value = " << b << endl;
        cout << "value2 = " << c << endl;
    };
    f6();
    */
    int c = 5;
    auto f7 = [&c](){return --c;};

    cout << "fun() = " << f7() << endl;
    cout << "c = " << c << endl;
    return 0;
}
