#include <iostream>
using namespace std;

int main() {
	int a;
	float b;
	cout << "please enter Farenheit value: ";
	cin >> a;
	b = (a - 32) * 5.0/ 9.0;
	cout << "Celcius value is " << b << endl;
}