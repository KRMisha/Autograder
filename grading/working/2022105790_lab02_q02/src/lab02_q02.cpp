#include <iostream>
using namespace std;

int main() {
	int A, B, sum, sub, mult, rem;
	float div;
	cout << "Please enteer two integer values: ";
	cin >> A >> B;
	sum = A + B;
	sub = A - B;
	mult = A * B;
	rem = A % B;
	div = (float)A / B;
	cout << A << " + " << B << " = " << sum << endl;
	cout << A << " - " << B << " = " << sub << endl;
	cout << A << " * " << B << " = " << mult << endl;
	cout << A << " / " << B << " = " << div << endl;
	cout << A << " % " << B << " = " << rem << endl;
}