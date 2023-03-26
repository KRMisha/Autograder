#include <iostream>
using namespace std;

int main() {
	float Fa;
	cout << "Please enter Fahrenheit value: ";
	cin >> Fa;
	float Ce = (5.0/9.0) * (Fa - 32);
	cout << "Celsius value is " << Ce << endl;
}