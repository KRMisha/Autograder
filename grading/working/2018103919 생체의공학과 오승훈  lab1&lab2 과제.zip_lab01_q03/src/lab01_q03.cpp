#include <iostream>
using namespace std;

//sizeof()의 기능은 자료형의 size를 알려주는 것이다.
int main(void)
{
	cout << "(7==5):" << (7 == 5) << endl;
	cout << "(7>=5):" << (7 >= 5) << endl;
	cout << "(7!=5):" << (7 != 5) << endl;
	cout << "(7<=5):" << (7 <= 5) << endl;
	cout << "(7>=5 ? 100 : -100): " << (7 >= 5? 100 : -100) << endl;

	return 0;
}
