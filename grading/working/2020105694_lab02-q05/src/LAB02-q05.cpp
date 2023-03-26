#include <iostream>
using namespace std;

int main() {
	float F;
	cout << "Please enter Fahrenheit value: ";
	cin >> F;

	float C = 5.0f / 9.0f * (F - 32);
	cout << "Celsius value is " << C;

}