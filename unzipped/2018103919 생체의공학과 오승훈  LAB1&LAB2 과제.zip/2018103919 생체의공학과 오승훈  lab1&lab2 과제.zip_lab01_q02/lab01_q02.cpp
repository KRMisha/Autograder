#include <iostream>
using namespace std;

//sizeof()�� ����� �ڷ����� size�� �˷��ִ� ���̴�.
int main(void)
{
	unsigned short siX;
	unsigned iX;//(int) ���� ����
	long liX;
	long long lliX;
	cout << "sizeof(siX) :" << sizeof(unsigned short) << endl;
	cout << "sizeof(iX) :" << sizeof(unsigned) << endl;
	cout << "sizeof(liX) :" << sizeof(long) << endl;
	cout << "sizeof(lliX) :" << sizeof(long long) << endl;

	return 0;
}
