# include <iostream>

using namespace std;

int main() {
	cout << "(7 == 5):" << int(7==5) << endl;
	cout << "(7 >= 5):" << int(7>=5) << endl;
	cout << "(7 != 5):" << int(7 != 5) << endl;
	cout << "(7 <= 5):" << int(7 <= 5) << endl;
	cout << "(7 >= 5 ? 100 : -100): " << int(7 >= 5 ? 100 : -100) << endl;
}
