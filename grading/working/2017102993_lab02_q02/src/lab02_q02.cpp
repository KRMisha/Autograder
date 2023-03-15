#include <iostream>
using namespace std;

int main()
{
	int A, B, sum, sub, mul,mod;
	float div;

	cout << "Please enter two integer values: ";
	cin >> A >> B;

	sum = A + B;
	sub = A - B;
	mul = A * B;
	div = float(A) / B;
	mod = A % B;

	cout << A << " + " << B << " = " << sum << endl;
	cout << A << " - " << B << " = " << sub << endl;
	cout << A << " * " << B << " = " << mul << endl;
	cout << A << " / " << B << " = " << div << endl;
	cout << A << " % " << B << " = " << mod;
}