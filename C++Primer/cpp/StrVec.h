#ifndef STRVEC_H_INCLUDED
#define STRVEC_H_INCLUDED
#include<string>
#include<memory>
#include<stdexcept>
using namespace std;
#define Default_size (5)
typedef string::size_type size_type;
class StrVec{
public:

    StrVec(size_type Size){
        elements = new string[Size];
        Beg = elements;
        End = elements+Size;
    }
    StrVec(){
        elements = new string[Default_size];
        Beg = elements;
        End = elements + Default_size;
    }
    StrVec(initializer_list<string> il){
        elements = new string[il.size()];
        Beg = elements;
        End = elements+il.size();
        string *p = elements;
        for(auto i:il){
            *p = i;
            p++;
        }
    }
    string* begin()const{
        return this->Beg;
    }
    string* end()const{
        return this->End;
    }
    friend ostream &operator << (ostream &os,const StrVec &Vec);
    bool empty()const{
        return (this->begin() == this->end());
    }
    size_type size()const{
        return (End-Beg);
    }
    string& operator [] (size_type p){
        check(p,"[] index out of StrVec!");
        return elements[p];
    }
    const string& operator [] (size_type p)const{
        check(p,"[] index out of StrVec!");
        return elements[p];
    }
private:
    string *Beg,*End;
    string *elements;
    void check(size_type i,const string &msg) const{
        if(i >= (this->size()))
            throw out_of_range(msg);
    }
};

ostream &operator << (ostream &os,const StrVec &Vec){
    for(string*it = Vec.begin();it != Vec.end();++it){
        os << *it << " ";
    }
    return os;
}
#endif // STRVEC_H_INCLUDED
