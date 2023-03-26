#include <iostream>
using namespace std;

// sizeof 함수의 기능: 프로그래머가 만든 소스코드에서 메모리 공간을 실제 몇 byte를 점유하는지 확인
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