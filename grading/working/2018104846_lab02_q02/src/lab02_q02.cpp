#include <iostream>

using namespace std;

int main() {
	int A, B, sum, sub, mult, div, modf;
	cout << "please enter two integer values: " << flush;
	cin >> A >> B;
	sum = A + B;
	sub = A - B;
	mult = A * B;
	div = A / B;
	modf = A % B;
	cout << "A + B = " << sum << endl;
	cout << "A - B = " << sub << endl;
	cout << "A * B = " << mult << endl;
	cout << "A / B = " << div << endl;
	cout << "A % B = " << modf << endl;
}