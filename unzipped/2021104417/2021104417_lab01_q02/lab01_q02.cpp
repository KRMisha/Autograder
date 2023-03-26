#include <iostream>
using namespace std;

// sizeof()는 변수나 자료형의 크기를 알고 싶을 때 사용하는 함수
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