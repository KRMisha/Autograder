#include <iostream>
using namespace std;

int main() {
	int a, b, c ;

	cout << "Please enter your integer numbers" << endl;
	cout << "A: ";
	cin >> a ;
	cout << "B: ";
	cin >> b;

	c = a;
	a = b;
	b = c;

	cout << "A: " << a << endl;
	cout << "B: " << b;
}