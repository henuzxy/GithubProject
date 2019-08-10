#include"student.h"
#include"StrVec.h"
#include<vector>
int main(void){
    Student zxy("henuzxy",22);
    Student hpf("henuhpf",23);
    Student zmq = {"henuzmq",21};
    const StrVec vec({"henuzxy","henuhpf","henuzmq"});
    cout << vec[0] << endl;

    return 0;
}
