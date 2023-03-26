#include <iostream>

using namespace std;

int main() {
	int A, B, middle;

	cout << "Please enter two integer values:" << endl << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;

	middle = B;
	B = A;
	A = middle;

	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B;
}