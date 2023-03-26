#include <iostream>
using namespace std;

int main() {
	double F, C;
	cout << "Please enter Fahrenheit value:";
	cin >> F;
	C = (F - 32)/1.8;
	cout << "Celsius value is " << C;
}