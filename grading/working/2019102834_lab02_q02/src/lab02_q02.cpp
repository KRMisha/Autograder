#include <iostream>
using namespace std;

int main() {
    int A,B,sum,sub,mult,remain;
    float div;
    cout<<"Please enter two integer values:"<<endl;
    cin>>A>>B;
    sum=A+B;
    sub=A-B;
    mult=A*B;
    remain=A%B;
    div=(float)A/B;

    cout<<"A+B="<<sum<<endl;
    cout<<"A-B="<<sub<<endl;
    cout<<"A*B="<<mult<<endl;
    cout<<"A/B="<<div<<endl;
    cout<<"A%B="<<remain<<endl;
}