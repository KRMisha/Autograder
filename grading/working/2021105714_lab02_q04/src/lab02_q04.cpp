#include <iostream>
using namespace std;

int main() {
	int A, B, t;
	
	cout << "Please enter two integer values:" << "\nA : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	t = A;
	A = B;
	B = t;
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;
}