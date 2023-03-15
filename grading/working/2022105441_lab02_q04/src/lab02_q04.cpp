#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	cout << "두 정수를 입력해주세요." << endl;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	C = A;
	A = B;
	B = C;
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;
}