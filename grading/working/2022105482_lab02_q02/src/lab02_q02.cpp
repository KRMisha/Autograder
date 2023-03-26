#include <iostream>

using namespace std;

int main()
{
	int x, y, v1, v2, v3, v4, v5;
	cout << "Please enter two integer values: ";
	cin >> x >> y;
	v1 = x + y;
	v2 = x - y;
	v3 = x * y;
	v4 = x / y;
	v5 = x % y;
	cout << x << " + " << y << " = " << v1 << endl;
	cout << x << " - " << y << " = " << v2 << endl;
	cout << x << " * " << y << " = " << v3 << endl;
	cout << x << " / " << y << " = " << v4 << endl;
	cout << x << " % " << y << " = " << v5 << endl;

}