#include<iostream>

using namespace std;


int main() {

	std::cout << "Please enter Fahrenheit value: " ;
	double F;
	cin >> F;
	double c;
	c = (5.0 / 9.0) * (F - 32);
	std::cout << "Celcius value is " << c << endl;
}