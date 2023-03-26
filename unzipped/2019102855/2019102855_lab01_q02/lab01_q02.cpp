#include <iostream>
using namespace std;
/* sizeof()의 기능: 변수의 크기를 확인할 때 사용한다.
sizeof()함수 내에 변수명이나 데이터타입을 넣으면 그 크기를 리턴한다.*/
int main(){
    unsigned short siX;
    unsigned iX;
    long liX;
    long long lliX;
    cout << "sizeof(siX):" << sizeof(siX) <<endl;
    cout << "sizeof(iX):" << sizeof(iX) <<endl;
    cout << "sizeof(liX):" << sizeof(liX) <<endl;
    cout << "sizeof(lliX):" << sizeof(lliX) <<endl;
}
