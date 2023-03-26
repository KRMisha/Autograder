#include <iostream>
using namespace std;
int main() {
	int c, f;
	cout << "Please enter Fahrenheit : ";
	cin >> f;
	c = 5.0 / 9.0 * (f - 32.0);
	cout << "Celsius : " << c;
}