#include <iostream>
using namespace std;

int main() {
	int F, C;
	cout << "Please enter Fahrenhit value: "; cin >> F;
	C = 5.0 / 9.0 * (F - 32);
	cout << "Celcius value is " << C;
}