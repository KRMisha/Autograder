# include <iostream>

using namespace std;

// sizeof()의 기능 : 괄호 안의 값의 byte단위로 크기를 알려줌
int main() {
	unsigned short siX;
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(unsigned short) << endl;
	cout << "sizeof(iX): " << sizeof(unsigned) << endl;
	cout << "sizeof(liX):" << sizeof(long) << endl;
	cout << "sizeof(lliX):" << sizeof(long long) << endl;
}