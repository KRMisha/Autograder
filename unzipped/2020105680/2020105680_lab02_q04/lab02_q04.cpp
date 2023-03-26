#include <iostream>

using namespace std;

int main() {
	cout << "Please enter two integer values: " << endl;
	
	int a, b;
	cout << "A : ";
	cin >> a;
	cout << "B : ";
	cin >> b;
	int temp = a;
	a = b;
	b = temp;
	cout << "value of A is : " << a<<endl;
	cout << "value of B is : " << b << endl;
}