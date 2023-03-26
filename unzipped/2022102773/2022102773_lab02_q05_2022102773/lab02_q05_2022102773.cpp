#include <iostream>
using namespace std;

int main() {
	float frht, clcs;

	cout << "Please enter Fahrenheit value: ";
	cin >> frht;

	clcs = 5.00f / 9.00f * (frht - 32.0f);
	cout << "Celcius value is " << clcs;

}