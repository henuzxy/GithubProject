#ifndef STRVECPTR_H_INCLUDED
#define STRVECPTR_H_INCLUDED
#include"StrVec.h"

class StrVecPtr{
public:
    StrVecPtr(string &str){
        ptr = &str;
    }
    StrVecPtr(){
    }
    STrVecPtr(string * _ptr){
        ptr = _ptr;
    }
    StrVecPtr& operator = (string &str){
        this->ptr = &str;
        return *this;
    }
    string& operator * ()const{
            return *ptr;
    }
private:
    int curr;
    string *ptr;

};


#endif // STRVECPTR_H_INCLUDED
