#include <iostream>

using namespace std;

int main() {
	int i1 = 2, i2 = 5, i3 = -3;
	double d1 = 2.0, d2 = 5.0, d3 = -0.5;
	cout << i1 + (i2 * i3) << '\n' << i1 * (i2 + i3) << '\n' << i1 / (i2 + i3) << '\n' << i1 / i2 + i3 << '\n';
	cout << 3 + 4 + 5 / 3 << '\n' << (3 + 4 + 5) / 3 << '\n' << d1 + (d2 * d3) << '\n' << d1 + d2 * d3 << '\n' << d1 / d2 - d3 << '\n';
	cout << d1 / (d2 - d3) << '\n' << d1 + d2 + d3 / 3 << '\n' << (d1 + d2 + d3) / 3;
}



