#include <iostream>
using namespace std;

//sizeof 함수는 데이터의 크기를 알기 위한 함수로, 특정한 변수형의 크기를 확인 할 때 사용됩니다. 

int main(){
    unsigned short siX;
    unsigned iX;
    long liX;
    long long lliX;
    
    cout << "sizeof(siX):" << sizeof(siX) << endl;
    cout << "sizeof(iX):" << sizeof(iX) << endl;
    cout << "sizeof(liX):" << sizeof(liX) << endl;
    cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}
