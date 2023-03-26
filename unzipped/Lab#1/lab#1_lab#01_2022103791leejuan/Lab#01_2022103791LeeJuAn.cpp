#include <iostream>
using namespace std;
int function1() {
	int x, y;
	x = 10;
	y = 20;
	cout << x << endl;
	cout << y << endl;
	cout << endl;
	return 0;
}
int function2() {
	unsigned short siX;
	unsigned iX;
	long IiX;
	long long IIiX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" << sizeof(siX) << endl;
	cout << "sizeof(IiX):" << sizeof(siX) << endl;
	cout << "sizeof(IIiX):" << sizeof(siX) << endl;
	cout << endl;
	return 0;
}

int function3() {
	cout << "(7==5):" << (7 == 5) << endl;
	cout << "(7>=5):" << (7 >= 5) << endl;
	cout << "(7!=5):" << (7 != 5) << endl;
	cout << "(7<=5):" << (7 <= 5) << endl;
	cout << "(7>=5 ? 100 : -100):" << (7 >= 5 ? 100 : -100) << endl;
	cout << endl;
	return 0;
}
int function4() {
	const float PI = 3.14;
	char ch1 = 65;
	char ch2 = 97;
	cout << PI << endl;
	cout << ch1 << endl;
	cout << ch2 << endl;
	cout << endl;
	return 0;
}
int function5() {
	int x, y, sum, mult;
	float div;
	cin >> x >> y;
	sum = x + y;
	mult = x * y;
	div = x / (float)y;
	cout << x << '\t' << y << endl;
	cout << "x + y = " << sum << endl;
	cout << "x * y = " << mult << endl;
	cout << "x / y = " << div << endl;
	cout << endl;
	return 0;
}
int printingMyName() {
	cout << "My name is 이주안" << endl;
	cout << endl;
	return 0;
}
int calculator1() {
	int x, y;
	cout << "Please enter two integer values" << endl;
	cin >> x >> y;
	cout << "1) x+y" << endl << x + y << endl;
	cout << "2) x-y" << endl << x - y << endl;
	cout << "3) x*y" << endl << x * y << endl;
	cout << "4) x/y" << endl << x / y << endl;
	cout << "5) x%y" << endl << x % y << endl;
	cout << endl;
	return 0;
}
int calculator2() {
	int i1 = 2, i2 = 5, i3 = -3;
	double d1 = 2.0, d2 = 5.0, d3 = -0.5;
	cout << "1) i1 + (i2 * i3)" << endl << i1 + (i2 * i3) << endl;
	cout << "2) i1* (i2 + i3)" << endl << i1* (i2 + i3) << endl;
	cout << "3) i1 / (i2 + i3)" << endl << i1 / (i2 + i3) << endl;
	cout << "4) i1 / i2 + i3" << endl << i1 / i2 + i3 << endl;
	cout << "5) 3 + 4 + 5 / 3)" << endl << 3 + 4 + 5 / 3 << endl;
	cout << "6) (3 + 4 + 5) / 3" << endl << (3 + 4 + 5) / 3 << endl;
	cout << "7) d1 + (d2 * d3)" << endl << d1 + (d2 * d3) << endl;
	cout << "8) d1 + d2 * d3" << endl << d1 + d2 * d3 << endl;
	cout << "9) d1 / d2 – d3" << endl << d1 / d2 - d3 << endl;
	cout << "10) d1 / (d2 – d3)" << endl << d1 / (d2 - d3) << endl;
	cout << "11) d1 + d2 + d3 / 3" << endl << d1 + d2 + d3 / 3 << endl;
	cout << "12) (d1 + d2 + d3) / 3" << endl << (d1 + d2 + d3) / 3 << endl;
	cout << endl;
	return 0;
}
int changeInt() {
	int a, b, hand;
	cout << "Please enter two integer values" << endl;
	cout << "A : ";
	cin >> a;
	cout << "B : ";
	cin >> b;
	hand = a;
	a = b;
	b = hand;
	cout << "value of A is : " << a << endl;
	cout << "value of B is : " << b << endl;
	cout << endl;
	return 0;
}
int changeF2C() {
	double fahrenheit, celsius;
	cout << "Please enter Fahrenheit values : ";
	cin >> fahrenheit;
	celsius = (fahrenheit - 32) * 5.0 / 9.0;
	cout << "Celcius value is " << celsius << endl;
	cout << endl;
	return 0;
}
int main() {
	function1();
	function2();
	function3();
	function4();
	function5();
	printingMyName();
	calculator1();
	calculator2();
	changeInt();
	changeF2C();
}