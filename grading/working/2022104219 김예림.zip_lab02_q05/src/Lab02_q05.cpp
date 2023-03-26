# include <iostream>

using namespace std;

int main() {
	float fahrenheit, celsius;

	cout << "Pleast enter Fahrenheit value: ";
	cin >> fahrenheit;
	
	celsius = (float(5.0 / 9.0)) * (fahrenheit - 32);

	cout << "Celsius value is " << celsius << endl;
}