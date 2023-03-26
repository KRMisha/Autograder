#include <iostream>
using namespace std;

int main() {
	double f, c;
	cout << "Please enter Fahrenheit value: ";
	cin >> f;
	c = 5.0 / 9.0 * (f - 32);
	cout << "Celcius value is " << c << endl;
}