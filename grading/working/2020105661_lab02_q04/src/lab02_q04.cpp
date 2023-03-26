#include <iostream>

using namespace std;

int main() {
	int A, B, temp;
	cout << "Please enter two integer values: " << endl;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	temp = A;
	A = B;
	B = temp;
	cout << "values of A is : "  << A << endl;
	cout << "values of B is : " << B << endl;
}