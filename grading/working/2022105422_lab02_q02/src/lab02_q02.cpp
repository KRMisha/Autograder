#include <iostream>
using namespace std;

int main()
{
	int A, B;
	cout << "Please enter two integer values:";
	cin >> A >> B;
	int sum, sub, mult, mod;
	float div;
	sum = A + B;
	sub = A - B;
	mult = A * B;
	div = float(A) / float(B);
	mod = A % B;

	cout << A <<" + "<< B <<" = " << sum << endl;
	cout << A <<" - "<< B <<" = " << sub << endl;
	cout << A <<" * "<< B <<" = " << mult << endl;
	cout << A <<" / "<< B << " = " << div << endl;
	cout << A <<" % "<< B <<" = " << mod << endl;
}