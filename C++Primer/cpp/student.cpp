#include"student.h"
#include<iostream>

using namespace std;
student::student(string _name){
    name = _name;
}
void student::show(){
    cout << name << endl;
}
