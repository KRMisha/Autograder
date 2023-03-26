#include <iostream>
using namespace std;

int main() {
	int farh, celc;

	cout << "Please enter Farenheit Values: " << endl;
	cin >> farh;

	celc = 5 / 9 * (farh - 32);

	cout << "Celcius value is " << celc;
}