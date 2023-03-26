#include <iostream>

using namespace std;

int main() {

	cout << "Please enter Fahrenheit value: ";

	float C;
	float F;
	cin >> F;
	C = 5.0f / 9.0f * ( F - 32);

	cout << "Celsius value is " << C << endl;
}


