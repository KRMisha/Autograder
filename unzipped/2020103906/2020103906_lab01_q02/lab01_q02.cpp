#include<iostream>

using namespace std;

/*sizeof()�Լ��� ��ü�� �������ִ� ����Ʈ�� ���差(storage)�� ũ�⸦ �˰���� �� ����Ѵ�.*/
int main() {
	unsigned short siX; // (int) ���� ����
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(iX) << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}
//unsigned�� ���� ������ �������� �ʰ� ����� ����θ�
//������ ��Ÿ������ �ϴ°�
//ex) -4000~400�̶�� 0~8000��Ÿ���� �̷��ʳ�?