#include <iostream>
using namespace std;

// sizeof()함수는 어떤 데이터 type의 size를 반환.

int main()
{
	unsigned short siX;
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX) : " << sizeof(siX) << endl;
	cout << "sizeof(iX) : " << sizeof(iX) << endl;
	cout << "sizeof(liX) : " << sizeof(liX) << endl;
	cout << "sizeof(lliX) : " << sizeof(lliX) << endl;
}