#include <iostream>

using namespace std;

int main() {
	// sizeof()�� �޸� ������ ũ�⸦ byte ������ return�մϴ�.
	unsigned short siX; // (int) ���� ����
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(unsigned short) << endl;
	cout << "sizeof(iX):" << sizeof (unsigned) << endl;
	cout << "sizeof(liX):" << sizeof(long) << endl;
	cout << "sizeof(lliX):" << sizeof(long long) << endl;
}