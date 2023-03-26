#include<iostream>

using namespace std;

int main() {
	cout << "(7 == 5):" << ((7 == 5) ? 1 : 0) << endl;
	cout << "(7 >= 5):" << ((7 >= 5) ? 1 : 0) << endl;
	cout << "(7 != 5):" << ((7 != 5) ? 1 : 0) << endl;
	cout << "(7 <= 5):" << ((7 <= 5) ? 1 : 0) << endl;
	cout << "(7 >= 5 ? 100 : -100): " << ((7 >= 5) ? 100 : -100) << endl;
}