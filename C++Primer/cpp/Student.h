#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include<iostream>
#include<string>

using namespace std;

class Student{
public:
    Student(){
    }
    Student(string _name,int _age):name(_name),age(_age){
    }
    string getname() const{
        return this->name;
    }
    int getage() const{
        return this->age;
    }
    friend istream& operator >> (istream& is,Student &stu);//把重载输入运算符>>定义为友元
private:
    string name;
    int age;
};

ostream& operator << (ostream& os,const Student &stu){
    os << stu.getname() << " " << stu.getage();
    return os;
}

istream& operator >> (istream& is,Student &stu){
    is >> stu.name >> stu.age;
    return is;
}
bool operator == (const Student &lstu,const Student &rstu){
    return ((lstu.getname() == rstu.getname()) && (lstu.getage() == rstu.getage()));
}
bool operator != (const Student &lstu,const Student &rstu){
    return !(lstu == rstu);
}
#endif // STUDENT_H_INCLUDED
