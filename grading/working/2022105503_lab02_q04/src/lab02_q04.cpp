#include<iostream>
using namespace std;

int main() {
	int A = 0, B = 0;
	cout << "Please enter two integer values:" << endl << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	int temp = A;
	A = B;
	B = temp;
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;
}