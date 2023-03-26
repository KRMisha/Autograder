#include <iostream>
using namespace std;

int main() 
{
	int A, B, C;
	cin >> A >> B;
	C = A;
	A = B;
	B = C;
	cout << "A = " << A << ", B = " << B;
}