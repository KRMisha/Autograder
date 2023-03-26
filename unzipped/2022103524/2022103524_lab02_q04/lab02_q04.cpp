#include <iostream>
using namespace std;

int main() {
	int a, b, t;
	cout << "Please enter two integer values: " << endl;
	cout << "A: "; cin >> a;
	cout << "B: "; cin >> b;

	t = a;
	a = b;
	b = t;

	cout << "value of A is: " << a << endl;
	cout << "value of B is: " << b << endl;
}