#include <iostream>
using namespace std;

/*
sizeof(변수 or 자료형)
해당 함수는 구문 내의 변수 혹은 자료형의 크기를 표현하는 함수입니다.
해당 크기의 단위는 byte입니다.

short 자료형은 2bytes
int와 long 자료형은 4bytes
long long 자료형은 8bytes
의 크기를 가지는 자료형입니다.
*/

int main()
{
	unsigned short siX; // (int) 생략 가능
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}