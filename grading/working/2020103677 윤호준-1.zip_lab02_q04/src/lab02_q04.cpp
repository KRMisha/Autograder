#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	cout << "Please enter two integer values: ";
	cin >> A >> B;
	cout << "A : " << A << endl;
	cout << "B : " << B << endl;
	C = A;
	A = B;
	B = C;
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;

}
