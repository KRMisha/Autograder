#include <iostream>
using namespace std;

//sizeof() 함수는 괄호 안에 들어간 데이터가 차지하고 있는 메모리 공간을 byte단위로 return 한다.
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