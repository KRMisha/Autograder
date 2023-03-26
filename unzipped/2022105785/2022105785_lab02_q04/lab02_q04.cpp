#include <iostream>
using namespace std;

int main() {
	int A, B, temp;
	cout << "Please enter two integer values: " << '\n' << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	temp = A;
	A = B;
	B = temp;
	cout << "value of A is : " << A << endl;
	cout << "value of A is : " << B << endl;
}
	