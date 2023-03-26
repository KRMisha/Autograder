#include <iostream>

using namespace std;

// sizeof() 함수는 해당 변수, 혹은 자료형의 메모리 크기를 반환한다.

int main()
{
    unsigned short siX;
    unsigned iX;
    long liX;
    long long lliX;

    cout << "sizeof(siX):" << sizeof(siX) << endl;
    cout << "sizeof(iX):" << sizeof(iX) << endl;
    cout << "sizeof(liX):" << sizeof(liX) << endl;
    cout << "sizeof(lliX):" << sizeof(lliX) << endl;

    return 0;
}