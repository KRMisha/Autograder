#include <iostream>
using namespace std;

//sizeof()�� ����� �ڷ����� size�� �˷��ִ� ���̴�.
int main(void)
{
	cout << "(7==5):" << (7 == 5) << endl;
	cout << "(7>=5):" << (7 >= 5) << endl;
	cout << "(7!=5):" << (7 != 5) << endl;
	cout << "(7<=5):" << (7 <= 5) << endl;
	cout << "(7>=5 ? 100 : -100): " << (7 >= 5? 100 : -100) << endl;

	return 0;
}
