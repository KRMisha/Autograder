#include <iostream>
using namespace std;

int main() 
{
	int a=6, b=2 d=8, e=4, f=12, g=3, h=0;
	cout << "Please enter two integer value : " << "";
	cin >> a >> b;

	d = a + b;
	e = a - b;
	f = a * b;
	g = a / b;
	h = a % b;

	cout << a << " + " << b << " = " << d << endl;
	cout << a << " - " << b << " = " << e << endl;
	cout << a << " * " << b << " = " << f << endl;
	cout << a << " / " << b << " = " << g << endl;
	cout << a << " % " << b << " = " << h << endl;
}