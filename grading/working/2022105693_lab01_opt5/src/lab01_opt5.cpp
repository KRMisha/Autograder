#include <iostream>
using namespace std;

int main() {
	int fah;
    cout << "Please enter Fahrenheit value : ";
    cin >> fah;
    cout << "Celsius value is " << (5.f / 9 * (fah - 32)) << endl;
}