#include <iostream>
using namespace std;
int main() {
	float F, C;
	cout << "Please enter Fahrenheit value: " ;
	cin >> F;
	C = 5.0f / 9.0f * (F - 32);
	cout << "Celcius value is " << C << endl;
}