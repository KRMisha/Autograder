#include <iostream>
using namespace std;

int main()
{
	int A, B, C;
	cout << "please enter two integer values : " << endl << "A :";
	cin >> A;
	cout << "B :";
	cin >> B;

	C = A; //C��� ������ A�� �� ����
	A = B;
	B = C;
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;

}