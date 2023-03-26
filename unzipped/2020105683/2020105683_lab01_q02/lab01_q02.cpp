#include <iostream>
using namespace std;
//sizeof() 함수는 소스코드에서 메모리 공간을 실제 몇 byte를 차지하고 있는지 확인하기 위한 함수입니다.
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