#include <iostream>
using namespace std;
int main() {
	int A, B, sum, sub, multi, div, rest;
	cout << "please enter two integer values: " ;
	cin >> A >> B;
	sum = A + B;
	sub = A - B;
	multi = A * B;
	div = A / B;
	rest = A % B;
	cout << A << " + " << B << " = " << sum << endl;
	cout << A << " - " << B << " = " << sub << endl;
	cout << A << " * " << B << " = " << multi << endl;
	cout << A << " / " << B << " = " << div << endl;
	cout << A << " % " << B << " = " << rest << endl;
}
