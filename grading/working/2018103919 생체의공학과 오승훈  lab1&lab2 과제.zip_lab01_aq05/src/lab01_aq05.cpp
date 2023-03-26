#include <iostream>
using namespace std;

int main(void)
{
	float A;
	cout << "please enter Fahrenheit value: " ;
	cin >> A;
	A = 5.0 / 9.0 * (A - 32);
	cout<< "Celsius value is " << A << endl;
	return 0;
}
