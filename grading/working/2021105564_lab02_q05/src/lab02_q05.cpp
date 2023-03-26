#include <iostream>
using namespace std;
int main() {
	int f;
	float c;
	cout << "Please enter Fahrenheit value: ";
	cin >> f;
	c = 5.0 / 9.0 * (f - 32);
	cout << "Celsius value is " << c;
}