# include <iostream>

using namespace std;

int main() {
	int A, B, sum, sub, mult;
	float div, rem;

	cout << "Please enter two integer values: ";
	cin >> A >> B;

	sum = A + B;
	sub = A - B;
	mult = A * B;
	div = A / B;
	rem = A % B;

	cout << A << " + " << B << " = " << sum << endl;
	cout << A << " - " << B << " = " << sub << endl;
	cout << A << " * " << B << " = " << mult << endl;
	cout << A << " / " << B << " = " << div << endl;
	cout << A << " % " << B << " = " << rem << endl;
}