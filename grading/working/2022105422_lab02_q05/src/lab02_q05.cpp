#include <iostream>
using namespace std;

int main()
{
	double C, F;
	cout << "Please enter Fahrenheit value: "; cin >> F;
	C = (5.0l) / (9.0l) * (F - (32.0l)), F = (9.0l) / (5.0l) * (C + (32.0l));
	cout << "Celsius value is " << C;
}