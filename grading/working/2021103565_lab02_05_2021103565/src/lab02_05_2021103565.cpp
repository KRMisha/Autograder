#include <iostream>
using namespace std;

int main() {

	int C, F;

	cout << "Please enter Fahrenheit value: ";
	cin >> F;
	
	C = (5 / 9) * (F - 32);

	cout << "Celsius value is " << C << endl;
}