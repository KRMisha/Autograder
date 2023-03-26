#include <iostream>

using namespace std;

int main() {
	int A, B, a;
	cout << "Please enter two integer values" << endl;
	cout << "A :";
	cin >> A;
	cout << "B :";
	cin >> B;
	a = A;
	A = B;
	B = a;

	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;

}
//a앞에;가 없 -> 그 전줄에 ;...