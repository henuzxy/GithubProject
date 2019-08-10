#include"student.h"
#include"StrVec.h"
#include"StrVecPtr.h"
#include"PrintString.h"
#include<vector>
#include<algorithm>

class SmallInt{
public:
    SmallInt(int i = 0):val(i){}
    operator int () const{
        return val;
    }
private:
    size_t val;
};
int main(void){
//
//    Student zxy("henuzxy",22);
//    Student hpf("henuhpf",23);
//    Student zmq = {"henuzmq",21};
//    StrVec vec({"henuzxy","henuhpf","henuzmq"});
//    PrintString printer(cout,'#');
//    int a = 10,b = 2;
//    greater<int> com;
  //  cout << com(a,b) << endl;
    SmallInt val(2);
    cout << val << endl;// 这里吧val隐式的转化为了int，然后被输出。


    return 0;
}
