#include<iostream>
using namespace std;
//sizeof(����)Ȥ�� sizeof(������ Ÿ��)�� �Է��ϸ� 
//�Է��� ������ ������ Ÿ�� Ȥ�� �Է��� ������ Ÿ���� ũ�⸦ ��ȯ�Ѵ�.
int main() {

	unsigned short siX; // (int) ���� ����
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(unsigned short) << endl;
	cout << "sizeof(iX):" << sizeof(unsigned) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}