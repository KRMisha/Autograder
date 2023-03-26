#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "insert a number A: " << '\n';
	cin >> num;
	int num2;
	cout << "insert a number B: " << '\n';
	cin >> num2;
	cout << num << " + " << num2 << " = " <<  num + num2 << '\n';
	cout << num << " - " << num2 << " = " << num - num2 << '\n';
	cout << num << " * " << num2 << " = " << num * num2 << '\n';
	cout << num << " / " << num2 << " = " << num / num2 << '\n';
	cout << num << " % " << num2 << " = " << num % num2 << '\n';
  }