/*************************************************************************
	> File Name: test.c
	> Author:henuzxy 
	> Mail: 
	> Created Time: 2019年07月22日 星期一 16时20分42秒
 ************************************************************************/

#include<stdio.h>
#include<string>
#include<stdbool.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<iostream>

using namespace std;
int main(int argc,char *argv[]){
    string str = "abc";
    str = str*3;
    cout << str << endl;
    return 0;
}
