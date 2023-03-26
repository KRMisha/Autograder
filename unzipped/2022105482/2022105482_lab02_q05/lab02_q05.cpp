#include <iostream>
using namespace std;

int main()
{
	int cel;
	float fah;

	cout << "Please enter Fahrenheit value: ";
	cin >> cel;
	fah = 5.0 / 9.0 * (cel - 32);
	cout << "Celsius value is " << fah;
}