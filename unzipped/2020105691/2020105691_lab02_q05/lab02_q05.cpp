#include <iostream>

using namespace std;


int main() {

	float fahren, celsi;

	cout << "Please enter Fahrenheit value: ";
	cin >> fahren;
	celsi = 5.0 / 9.0 * (fahren - 32);
	
	cout << fahren << "F -> " << "Celsius value is " << celsi << endl;

}