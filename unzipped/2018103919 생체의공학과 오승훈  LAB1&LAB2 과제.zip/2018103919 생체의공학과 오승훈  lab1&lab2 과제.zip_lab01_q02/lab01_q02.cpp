#include <iostream>
using namespace std;

//sizeof()의 기능은 자료형의 size를 알려주는 것이다.
int main(void)
{
	unsigned short siX;
	unsigned iX;//(int) 생략 가능
	long liX;
	long long lliX;
	cout << "sizeof(siX) :" << sizeof(unsigned short) << endl;
	cout << "sizeof(iX) :" << sizeof(unsigned) << endl;
	cout << "sizeof(liX) :" << sizeof(long) << endl;
	cout << "sizeof(lliX) :" << sizeof(long long) << endl;

	return 0;
}
