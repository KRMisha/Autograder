#include <iostream>

using namespace std;

int main() {

	int i1 = 2, i2 = 5, i3 = -3;

	double d1 = 2.0, d2 = 5.0, d3 = -0.5;

	cout << "1) i1 + (i2 * i3)  : " << i1 + (i2 * i3) << endl;
	cout << "2) i1 + (i2 + i3)  : " << i1 + (i2 + i3) << endl;
	cout << "3) i1 / (i2 + i3)  : " << i1 / (i2 + i3) << endl;
	cout << "4) i1 / i2 + i3  : " << i1 / i2 + i3 << endl;
	cout << "5) 3 + 4 + 5 / 3  : " << 3 + 4 + 5 / 3 << endl;
	cout << "6) (3 + 4 + 5) / 3  : " << (3 + 4 + 5) / 3 << endl;
	cout << "7) d1 + (d2 * d3)  : " << d1 + (d2 * d3) << endl;
	cout << "8) d1 + d2 * d3  : " << d1 + d2 * d3 << endl;
	cout << "9) d1 / d2 - d3  : " << d1 / d2 - d3 << endl;
	cout << "10) d1 / (d2 - d3)  : " << d1 / (d2 - d3) << endl;
	cout << "11) d1 + d2 + d3 / 3  : " << d1 + d2 + d3 / 3 << endl;
	cout << "12) (d1 + d2 + d3) / 3  : " << (d1 + d2 + d3) /3  << endl;
} 