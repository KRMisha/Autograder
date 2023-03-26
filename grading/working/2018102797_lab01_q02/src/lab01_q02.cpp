#include<iostream>
using namespace std;
//메모리 공간을 실제로 얼마나 잡아먹는지 확인하는 기능
int main() {
    unsigned short siX;
    unsigned iX;
    long liX;
    long long llix;
    cout << "sizeof(siX): " << sizeof(siX) << endl;
    cout << "sizeof(iX): " << sizeof(iX) << endl;
    cout << "sizeof(liX): " << sizeof(liX) << endl;
    cout << "sizeouf(llix): " << sizeof(llix) << endl;
}