#include<iostream>

using namespace std;
//sizeof 함수는 자료형의 byte 수를 반환해주는 함수입니다.
int main() {
	unsigned short siX; 
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(unsigned short) << endl;
	cout << "sizeof(iX):" << sizeof(unsigned) << endl;
	cout << "sizeof(liX):" << sizeof(long) << endl;
	cout << "sizeof(lliX):" << sizeof(long long) << endl;
}