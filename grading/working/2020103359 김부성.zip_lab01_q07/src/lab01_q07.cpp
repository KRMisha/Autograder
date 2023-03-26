# include <iostream>
using namespace std;

int main() {
	int a, b,sum,minus,mult;
	float div, percent;
	cin >> a >> b;
	sum = a + b;
	minus = a - b;
	mult = a * b;
	div = float(a) / float(b);

	cout << a << " + " << b << " = " << sum << endl;
	cout << a << " - " << b << " = " << minus << endl;
	cout << a << " * " << b << " = " << mult << endl;
	cout << a << " / " << b << " = " << div << endl;
	cout << a << " % " << b << " = " << a % b << endl;
}