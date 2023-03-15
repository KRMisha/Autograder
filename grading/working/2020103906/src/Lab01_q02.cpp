#include<iostream>

using namespace std;

/*sizeof()함수는 객체가 가지고있는 바이트의 저장량(storage)의 크기를 알고싶을 때 사용한다.*/
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