#include <iostream>
using namespace std;

int main() {

	int x, y, sum, diff, mult;
	float div, modulus;

	cout << "Please input two numbers " << endl;
	cin >> x >> y;
	sum = x + y;
	diff = x - y;
	mult = x * y;
	modulus = x % y;
	div = float(x) / float(y);
	cout << x << '\t' << y << endl;
	cout << "x + y = " << sum << endl;
	cout << "x - y = " << diff << endl;
	cout << "x * y = " << mult << endl;
	cout << "x / y = " << div << endl;
	cout << "x % y = " << modulus << endl;
}