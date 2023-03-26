#include <iostream>
using namespace std;
int main() {
	int A, B, num;
	cout << "Please enter two integer values: " << endl;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	num = A;
	A = B;
	B = num;
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;
}