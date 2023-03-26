#include <iostream>

using namespace std;

// sizeof()의 기능: 타입(자료형)의 사이즈(크기)를 알 수 있는 함수이다.
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