#include <iostream>

using namespace std;

int main() {
	int a, b, sum, sub, mult, div, extra;
	cout << "Please enter two integer values: ";
	cin >> a >> b;
	sum = a + b;
	sub = a - b;
	mult = a * b;
	div = a / b;
	extra = a % b;

	cout << a << " + " << b << " = " << sum << endl;
	cout << a << " - " << b << " = " << sub << endl;
	cout << a << " * " << b << " = " << mult << endl;
	cout << a << " / " << b << " = " << div << endl;
	cout << a << " % " << b << " = " << extra << endl;
}