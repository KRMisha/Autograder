#include <iostream>
using namespace std;

int main()
{
	int val1, val2;
	cout << "Please enter two integer values: ";
	cin >> val1 >> val2;
	cout << val1 << " + " << val2 << " = " << val1 + val2 << endl;
	cout << val1 << " - " << val2 << " = " << val1 - val2 << endl;
	cout << val1 << " * " << val2 << " = " << val1 * val2 << endl;
	cout << val1 << " / " << val2 << " = " << val1 / val2 << endl;
	cout << val1 << " % " << val2 << " = " << val1 % val2 << endl;
	return 0;
}