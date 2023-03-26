#include <iostream>
using namespace std;

int main() {
	cout << "Please enter two integer values : ";
	int newInt1, newInt2;
	cin >> newInt1 >> newInt2;
	cout << newInt1 << " + " << newInt2 << " = " << newInt1 + newInt2 << endl;
	cout << newInt1 << " - " << newInt2 << " = " << newInt1 - newInt2 << endl;
	cout << newInt1 << " * " << newInt2 << " = " << newInt1 * newInt2 << endl;
	cout << newInt1 << " / " << newInt2 << " = " << (float)newInt1 / (float)newInt2 << endl;
	cout << newInt1 << " % " << newInt2 << " = " << newInt1 % newInt2 << endl;
}