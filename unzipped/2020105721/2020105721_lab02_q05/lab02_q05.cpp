#include <iostream>

using namespace std;

int main() {
	float Fahrenheit,Celsius;
	cout << "Please enter Fahrenheit value: ";
	cin >> Fahrenheit;
	Celsius = (5.0 / 9.0) * (Fahrenheit - 32);
	cout << "Celsius value is " << Celsius;
	
}