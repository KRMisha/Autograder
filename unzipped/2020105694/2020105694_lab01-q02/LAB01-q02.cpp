#include <iostream>
using namespace std;

//sizeof()은 괄호 안에 있는 변수형의 크기를 반환함으로써, 몇 바이트를 차지하는지 확인해준다.
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