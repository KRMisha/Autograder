#include <iostream>

using namespace std;

int main() {
	float fah, cel;
	cout << "Please enter Fahrenheit value: ";
	cin >> fah;
	cel = (5.0 / 9.0) * (fah - 32);
	cout << "Celsius value is " << cel << endl;
}