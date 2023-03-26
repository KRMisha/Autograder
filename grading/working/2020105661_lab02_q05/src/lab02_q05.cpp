#include <iostream>

using namespace std;

int main() {
	float value;
	cout << "Please enter Faahrenheit value: ";
	cin >> value;
	cout << "Celsius value is " << 5.0f/9.0f * (value - 32) << endl;
}