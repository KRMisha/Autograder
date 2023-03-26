#include <iostream>
using namespace std;

int main()
{
	int temp, a, b;
	cout << "Please enter two integer values: " << endl;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	temp = a;
	a = b;
	b = temp;
	cout << "value of A is : " << a << endl << "value of B is : " << b;
}
