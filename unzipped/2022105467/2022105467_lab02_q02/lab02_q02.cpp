#include <iostream>

int main() {
	int x, y;
	std::cout << "Please enter two integer values: ";
	std::cin >> x >> y;
	std::cout << x << " + " << y << "= " << (x + y) << std::endl;
	std::cout << x << " - " << y << "= " << (x - y) << std::endl;
	std::cout << x << " * " << y << "= " << (x * y) << std::endl;
	std::cout << x << " / " << y << "= " << ((float)x / (float)y) << std::endl;
	std::cout << x << " % " << y << "= " << (x % y) << std::endl;
}
