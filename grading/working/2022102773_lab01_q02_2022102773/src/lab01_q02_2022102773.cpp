#include <iostream>
using namespace std;

int main() {
	//sizeof() 함수는 괄호 내 입력된 패러미터의 데이터 타입이 메모리에서 차지하는 바이트 값를 return한다.
	unsigned short siX; // (int) 생략 가능
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}
