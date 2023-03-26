#include <iostream>
using namespace std;
int main() {
	cout << "Please enter two integer values:" << endl;
	int A, B, C;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	C = B;
	B = A;
	A = C;
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;
}