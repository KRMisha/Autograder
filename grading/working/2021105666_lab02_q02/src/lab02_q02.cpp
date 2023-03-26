#include <iostream>
using namespace std;

int main() {
	int x, y, z,j,sum, mult,div;
	cout << "Please enter two integer values:" << endl;
	cin >> x >> y;
	sum = x + y;
	mult = x * y;
	div = x / y;
	z = x % y;
	j = x - y;

	cout << x << '\t' << y << endl;
	cout << "x + y = " << sum << endl;
	cout << "x - y = " << j << endl;
	cout << "x * y = " << mult << endl;
	cout << "x / y = " << div << endl;
	cout << "x % y=" << z<<endl;
}