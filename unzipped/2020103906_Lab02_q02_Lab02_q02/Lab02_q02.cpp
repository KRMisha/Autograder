#include <iostream>

using namespace std;

int main() {

	int A, B, remain;
	float div;
	cout << "A의 값을 입력하시오: ";
	cin >> A;
	cout << "B의 값을 입력하시오: ";
	cin >> B;

	div = ((float)A) / ((float)B);
	remain = A % B;

	cout << "\n" << "1)A+B= " << (A + B) << endl;
	cout << '\n' << "2)A-B= " << (A - B) << endl;
	cout << "\n" << "3)A*B= " << (A * B) << endl;
	cout << '\n' << "4)A/B= " << div << endl;
	cout << '\n' << "4)A%B= " << remain << endl;
}