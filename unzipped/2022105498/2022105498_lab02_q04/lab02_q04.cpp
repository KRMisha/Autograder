#include <iostream>

using namespace std;


int main() {
	int A, B, tmp;

	cout << "Please enter two integer values:" << endl;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;

	tmp = A;
	A = B;
	B = tmp;

	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;

}

