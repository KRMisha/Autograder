#include <iostream>

using namespace std;

int main() {
	int x, y, sum, minus, mult, div, mod;
	cout << "Please enter two integer values: ";
	cin >> x >> y;
		sum = x + y;
		minus = x - y;
		mult = x * y;
		div = x / y;
		mod = x % y;
	
	cout << x << " + " << y << " = " << sum << endl;
	cout << x << " - " << y << " = " << minus << endl;
	cout << x << " * " << y << " = " << mult << endl;
	cout << x << " / " << y << " = " << div << endl;
	cout << x << " % " << y << " = " << mod << endl;

}


