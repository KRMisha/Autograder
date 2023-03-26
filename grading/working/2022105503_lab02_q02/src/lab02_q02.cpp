#include<iostream>
using namespace std;

int main() {
	int A = 0, B = 0;
	cout << "Please enter two integer values: ";
	cin >> A >> B;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << A << " - " << B << " = " << A - B << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << " / " << B << " = " << (float)A / B << endl;
	cout << A << " % " << B << " = " << A % B << endl;

}