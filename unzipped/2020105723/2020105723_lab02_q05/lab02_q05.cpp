#include <iostream>
using namespace std;

int main() {
	float celsius, fahrenheit;
	cout << " Please enter Fahrenheit value: ";
	cin >> fahrenheit;
	celsius = 5.0f / 9.0f * (fahrenheit - 32);
	cout << "Celsius value is " << celsius;

}