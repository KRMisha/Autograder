#include <iostream>

using namespace std;

int main() {
	int fah;
	float c;
	cout << "Please enter Fahrenheit value :";
	cin >> fah;
	c = float(5) / float(9) * (float(fah) - 32.0f);
	cout << "Celsius value is " << c << endl;

}

// 5/9 = 0