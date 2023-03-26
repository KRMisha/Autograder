#include<iostream>
using namespace std;

int main() {
	float F = 0.0;
	float C = 0.0;
	cout << "Please enter Fahrenheit value: ";
	cin >> F;
	C = 5.0f / 9.0f * (F - 32);
	cout << "Celsius value is " << C << endl;
}