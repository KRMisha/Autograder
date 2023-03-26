#include <iostream>

using namespace std;

int main() {
	int A, B;
	cout << "Please enter two integer values : " << endl;
	cin >> A >> B;
	int sum, min, mult, div2,div;
	sum = A + B;
	min = A - B;
	mult = A * B;
	div = A / B;
	div2 = A % B;

	cout << A << "+" << B << "=" << sum << endl;
	cout << A << "-" << B << "=" << min << endl;
	cout << A << "*" << B << "=" << mult << endl;
	cout << A << "/" << B << "=" << div << endl;
	cout << A << "%" << B << "=" << div2 << endl;
}