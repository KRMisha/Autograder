#include <iostream>
using namespace std;

/*
sizeof(���� or �ڷ���)
�ش� �Լ��� ���� ���� ���� Ȥ�� �ڷ����� ũ�⸦ ǥ���ϴ� �Լ��Դϴ�.
�ش� ũ���� ������ byte�Դϴ�.

short �ڷ����� 2bytes
int�� long �ڷ����� 4bytes
long long �ڷ����� 8bytes
�� ũ�⸦ ������ �ڷ����Դϴ�.
*/

int main()
{
	unsigned short siX; // (int) ���� ����
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}