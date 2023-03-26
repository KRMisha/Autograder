#include <iostream>
using namespace std;

int main() {
	float value1;
	cout << "Please enter Fahrenheit value : ";
	cin >> value1;
	value1 = 5.0 / 9.0 * (value1 - 32);
	cout << "Celsius value is " << value1;
}