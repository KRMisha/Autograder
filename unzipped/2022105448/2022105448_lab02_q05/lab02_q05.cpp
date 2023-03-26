#include <iostream>
using namespace std;

int main() {
	float F, C;
	cout << "Please enter Fahrenheit values: ";
	cin >> F;
	C = 5.0f / 9.0f * (F - 32.0f);
	cout << "Celsius value is " << C;
}