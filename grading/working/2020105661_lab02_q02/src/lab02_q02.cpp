#include <iostream>

using namespace std;

int main() {
	int value1, value2;
	cout << "Please enter two integer values: ";
	cin >> value1 >> value2;
	cout << value1 << " + " << value2 << " = " << value1 + value2 << endl;
	cout << value1 << " - " << value2 << " = " << value1 - value2 << endl;
	cout << value1 << " * " << value2 << " = " << value1 * value2 << endl;
	cout << value1 << " / " << value2 << " = " << value1 / value2 << endl;
	cout << value1 << " % " << value2 << " = " << value1 % value2 << endl;
}