#include <iostream>

using namespace std;
// sizeof()의 기능은 데이터의 크기(사이즈)를 나타냅니다!
int main() {
	unsigned short siX; // (int) 생략   가능 
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}