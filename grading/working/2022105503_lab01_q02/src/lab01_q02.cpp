#include<iostream>
using namespace std;
//sizeof(변수)혹은 sizeof(데이터 타입)을 입력하면 
//입력한 변수의 데이터 타입 혹은 입력한 데이터 타입의 크기를 반환한다.
int main() {

	unsigned short siX; // (int) 생략 가능
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(unsigned short) << endl;
	cout << "sizeof(iX):" << sizeof(unsigned) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}