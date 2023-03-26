#include <iostream>
using namespace std;
/*
sizeof()함수는 괄호안의 값을 byte단위의 크기로 알려주는 함수이다
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