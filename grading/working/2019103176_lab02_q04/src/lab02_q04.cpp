#include <iostream>
using namespace std;

int main()
{
	int A, B;

	cout << "Please enter two integer values : " << '\n' << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;

	int value;
	value = A;
	A = B;
	B = value;

	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;
}