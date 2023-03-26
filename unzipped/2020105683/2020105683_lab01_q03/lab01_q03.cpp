#include <iostream>
using namespace std;
int main() {
	int a, b, c, d, e;
	a = 7 == 5;
	b = 7 >= 5;
	c = 7 != 5;
	d = 7 <= 5;
	e = 7 >= 5 ? 100 : -100;
	cout << "(7 == 5):" << a << endl;
	cout << "(7 >= 5):" << b << endl;
	cout << "(7 != 5):" << c << endl;
	cout << "(7 <= 5):" << d << endl;
	cout << "(7 >= 5 ? 100 : -100):" << e << endl;
}