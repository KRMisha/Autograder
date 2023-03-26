#include <iostream>

using namespace std;

//sizeof 함수는 size를 확인 가능하도록 해주는 함수이다.
int main() {
    unsigned short siX; 
    unsigned iX;
    long liX;
    long long lliX;
    cout << "sizeof(siX):" << sizeof(siX) << endl;
    cout << "sizeof(iX):" << sizeof(iX) << endl;
    cout << "sizeof(liX):" << sizeof(liX) << endl;
    cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}