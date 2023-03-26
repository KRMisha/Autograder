#include <iostream>

using namespace std;

int main()
{
    int a = 7, b = 3, c = 100, d = -100;

    cout << "(7 == 5):" << (a == b) << endl;
    cout << "(7 >= 5):" << (a >= b) << endl;
    cout << "(7 != 5):" << (a != b) << endl;
    cout << "(7 <= 5):" << (a <= b) << endl;
    cout << "(7 >= 5 ? 100 : -100):" << (a >= b ? c : d) << endl;
}