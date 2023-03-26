#include <iostream>
using namespace std;

int main() {
	int c = 7 >= 5 ? 100 : -100;
	cout << "(7 == 5):" << bool(7 == 5) << endl;
	cout << "(7 >= 5):" << bool(7 >= 5) << endl;
	cout << "(7 != 5):" << bool(7 != 5) << endl;
	cout << "(7 <= 5):" << bool(7 <= 5) << endl;
	cout << "(7 >= 5 ? 100 : -100): " << c << endl;
}