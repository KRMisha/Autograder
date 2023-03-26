#include <iostream>
using namespace std;
int main() {
	double C = 0.0, F = 0.0;
	cout << "Please enter Fahreheit value: ";
	cin >> F;
	C = 5.0 / 9.0 * (F - 32);
	cout << "Celsius value is " << C;
}