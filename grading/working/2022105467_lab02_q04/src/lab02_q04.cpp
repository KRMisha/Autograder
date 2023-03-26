#include <iostream>

int main() {
	int a, b, temp;
	std::cout << "Please enter two integer values: " << std::endl;
	std::cout << "A : ";
	std::cin >> a;
	std::cout << "B : ";
	std::cin >> b;
	temp = a;
	a = b;
	b = temp;
	std::cout << "value of A is : " << a << '\n'
		<< "value of B is : " << b << std::endl;
}