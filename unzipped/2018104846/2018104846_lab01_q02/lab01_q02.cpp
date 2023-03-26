#include <iostream>

using namespace std;
/*sizeof()함수는 괄호안의 값의 byte단위로 크기를 알려주는
함수다. 이때 값은 변수 타입이나 변수이름을 넣으면 된다.*/
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