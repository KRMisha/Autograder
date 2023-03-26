#include <iostream>

using namespace std;

int main() {
	int x, y, sum, mult;
	float div;
	cin >> x >> y;
	sum = /*구현*/ x + y;
	mult = /*구현*/ x * y;
	div = /*구현*/ (x / double(y));
	cout << x << '\t' << y << endl;
	cout << "x + y = " << sum << endl;
	cout << "x * y = " << mult << endl;
	cout << "x / y = " << div << endl;
}

