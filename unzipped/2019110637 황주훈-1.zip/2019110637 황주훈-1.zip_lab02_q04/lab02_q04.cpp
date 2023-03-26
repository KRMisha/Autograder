#include <iostream>
using namespace std;
int main() {
	int x, y,z;
	cout << "x : ";
	cin >> x;
	cout << "y : ";
	cin >> y;
	z = x;
	x = y;
	y = z;
	cout << "x : " << x << endl << "y : " << y;
}