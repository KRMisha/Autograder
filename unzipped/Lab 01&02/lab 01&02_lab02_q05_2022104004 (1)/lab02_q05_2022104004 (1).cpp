#include <iostream>

using namespace std;

int main() {
	float C, F;
	cout << "Please enter a Fahrenheit value: " << endl;
	cin >> F;
	C = (5.0 / 9.0) * (F - 32);
	cout << "Celcius value is " << C << endl;
}