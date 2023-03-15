#include <iostream>

using namespace std;

int main() {

	float Celsius, Fahrenheit;

	cout << "Please enter Fahrenheit value : ";
	cin >> Fahrenheit;

	Celsius = 5 / 9 * (Fahrenheit - 32);

	cout << "Celsius value is " << Celsius << endl;

}