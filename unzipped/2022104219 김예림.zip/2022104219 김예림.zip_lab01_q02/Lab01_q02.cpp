# include <iostream>

using namespace std;

// sizeof()�� ��� : ��ȣ ���� ���� byte������ ũ�⸦ �˷���
int main() {
	unsigned short siX;
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(unsigned short) << endl;
	cout << "sizeof(iX): " << sizeof(unsigned) << endl;
	cout << "sizeof(liX):" << sizeof(long) << endl;
	cout << "sizeof(lliX):" << sizeof(long long) << endl;
}