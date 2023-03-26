#include <iostream>
using namespace std;

int main() {
	cout << "Please enter Fahrenheit value :";
	double a;
	double value;
	cin >> a;
	cout << "Celsius value is " << (5 / 9) * (a - 32) << endl;
}