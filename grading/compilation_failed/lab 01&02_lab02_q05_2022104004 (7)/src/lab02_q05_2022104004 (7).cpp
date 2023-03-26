#include <iostream>

using namespace std;

int main() {
	int A, B, sum, sub, mult, div, mod;
	cout << "Please enter two integers" << endl;
	cin >> A >> B;
	sum = A + B;
	sub = A - B;
	mult = A * B;
	div = A / B;
	mod = A % B;
	cout << "A + B=" << sum << endl;
	cout << "A - B=" << sub << endl;
	cout << "A * B=" << mult << endl;
	cout << "A / B=" << div << endl;
	cout << "A % B=" << mod << endl;
}