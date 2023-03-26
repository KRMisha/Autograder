#include <iostream>

using namespace std;

int main() {
	int Faren, Celsis;
	cout << "Please enter Fahrenheit values: ";
	cin >> Faren;
	Celsis = 5.0f/ 9.0f* (Faren - 32);
	cout << "Celsius value is : " << Celsis << endl;

}
