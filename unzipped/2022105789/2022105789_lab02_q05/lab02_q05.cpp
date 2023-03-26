#include <iostream>
using namespace std;

int main() {
	float x, y;

	cout << "Please enter Fahrenheit value: ";
	cin >> x;

	y = 5.0 / 9.0 * (x - 32);

	cout << "Celsius value is : " << y << endl;
}
