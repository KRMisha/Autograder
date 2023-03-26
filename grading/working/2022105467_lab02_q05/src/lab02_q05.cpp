#include <iostream>

int main() {
	int temp_f, temp_c;
	std::cout << "Please enter Fahrenheit value: ";
	std::cin >> temp_f;
	temp_c = 5.0 / 9.0 * (temp_f - 32);
	std::cout << "Celsius value is " << temp_c << std::endl;
}