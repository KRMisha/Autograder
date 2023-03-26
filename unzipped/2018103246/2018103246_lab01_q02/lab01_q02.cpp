#include <iostream>

using namespace std;

/*
sizeof() 함수는 메모리 공간을 차지하는 byte수를 return 합니다.
*/

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