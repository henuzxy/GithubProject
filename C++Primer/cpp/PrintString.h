#ifndef PRINTSTRING_H_INCLUDED
#define PRINTSTRING_H_INCLUDED
#include<iostream>
class PrintString{
public:
    PrintString(ostream &_os = std::cout,char _sep = ' '):
        os(_os),sep(_sep){}
    void operator()(const string &s) const{
        os << s << sep;
    }

private:
    ostream &os;
    char sep;
};


#endif // PRINTSTRING_H_INCLUDED
