#include <iostream>

using namespace std;

int main() {
	int x, y, sum, mult;
	float div;
	cin >> x >> y;
		sum = x + y;
		mult = x * y;
		div = float(x) / y;
	cout << x << '\t' << y << endl;
	cout << "x + y = " << sum << endl;
	cout << "x * y = " << mult << endl;
	cout << "x / y = " << div << endl;
}


