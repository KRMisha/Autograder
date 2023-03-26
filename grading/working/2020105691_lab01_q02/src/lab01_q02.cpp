#include <iostream>

using namespace std;

//sizeof(X) : 변수 X의 바이트 용량을 반환

int main() {
	unsigned short siX;
	unsigned iX;
	long liX;
	long long lliX;

	cout << "sizeof(siX): " << sizeof(siX) << endl;
	cout << "sizeof(iX): " << sizeof(iX) << endl;
	cout << "sizeof(liX): " << sizeof(liX) << endl;
	cout << "sizeof(lliX): " << sizeof(lliX) << endl;
}