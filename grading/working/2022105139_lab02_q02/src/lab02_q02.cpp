#include<iostream>

using namespace std;


int main() {
	std::cout << "Please enter two integer values : " ;
	int A = 0;
	int B = 0; std::cin >> A >> B;
	std::cout << A << "+" << B <<"=" << A + B << std::endl;
	std::cout << A << "-" << B << "=" << A - B << std::endl;
	std::cout << A << "*" << B << "=" << A * B << std::endl;
	std::cout << A <<"/" << B << "=" << A / B << std::endl;
	std::cout << A << "%" << B << "=" << A % B << std::endl;
}