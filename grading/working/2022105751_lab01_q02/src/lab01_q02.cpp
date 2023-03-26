#include <iostream>
using namespace std;
/*
sizeof() 의 기능:
자료형의 크기를 바이트 단위로 계산하는 연산자
*/
int main() {
	unsigned short siX; // (int) 생략 가능
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}