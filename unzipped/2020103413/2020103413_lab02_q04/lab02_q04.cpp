#include <iostream>
using namespace std;

int main() {
	int A, B;
	cout << "A: ";
	cin >> A;
	cout << "B: ";
	cin >> B;
	int tmp = 0;
	tmp = A;
	A = B;
	B = tmp;
	cout << "A = " << A << endl; 
	cout << "B = " << B << endl;
}