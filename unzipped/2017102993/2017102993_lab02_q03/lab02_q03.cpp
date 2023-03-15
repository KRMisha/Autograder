#include <iostream>
using namespace std;

int main()
{
	int i1 = 2, i2 = 5, i3 = -3;
	double d1 = 2.0, d2 = 5.0, d3 = -0.5;

	cout << (i1 + (i2 * i3)) << endl; //1
	cout << (i1 * (i2 + i3)) << endl; //2
	cout << (i1 / (i2 + i3)) << endl; //3
	cout << (i1 / i2 + i3) << endl; //4
	cout << (3 + 4 + 5 / 3) << endl; //5
	cout << ((3 + 4 + 5) / 3) << endl; //6
	cout << (d1 + (d2 * d3)) << endl; //7
	cout << (d1 + d2 * d3) << endl; //8
	cout << (d1 / d2 - d3) << endl; //9
	cout << (d1 / (d2 - d3)) << endl; //10
	cout << (d1 + d2 + d3 / 3) << endl; //11
	cout << ((d1 + d2 + d3) / 3); //12
}