#include <iostream>


using namespace std;

int main() {
	int A, B;
	int sum, sub, mul, div1, div2;
	cout << "Please enter two integer values: ";
	cin >> A >> B;
	sum = A + B;
	sub = A - B;
	mul = A * B;
	div1 = A / B;
	div2 = A % B;

	cout << "6 + 2 = " << sum << endl;
	cout << "6 - 2 = " << sub << endl;
	cout << "6 * 2 = " << mul << endl;
	cout << "6 / 2 = " << div1 << endl;
	cout << "6 % 2 = " << div2 << endl;

}