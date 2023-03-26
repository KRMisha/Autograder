#include <iostream>

using namespace std;

int main() {
	float F, C;
	cout << "Plase enter Fahrenheit value : ";
	cin >> F;
	C = 5.0f / 9.0f * (F - 32.0f);
	F = 9.0f / 5.0f * (C + 32.0f);
	cout << "Celsius value is " << C << endl;
}