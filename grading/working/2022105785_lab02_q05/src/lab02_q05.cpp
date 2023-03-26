#include <iostream>
using namespace std;

int main() {
	float Fahrenheit;
	cout << "Please enter Fahrenheit value: ";
	cin >> Fahrenheit;
	cout << "Celsius value is " << (5.0 / 9.0) * (Fahrenheit - 32);
}